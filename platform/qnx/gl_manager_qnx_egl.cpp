/**************************************************************************/
/*  egl_manager.cpp                                                       */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "gl_manager_qnx_egl.h"

#include "drivers/gles3/rasterizer_gles3.h"

// #ifdef EGL_ENABLED // this seems to pull some dependencies to GLAD
#ifdef QNX_ENABLED //

EGLConfig choose_config(EGLDisplay egl_display, int screenFormat) {
	struct {
		int red_size;
		int green_size;
		int blue_size;
		int alpha_size;
	} egl_conf_attr;
	
	// Get RGBA sizes from screen format
	switch (screenFormat) {
		case SCREEN_FORMAT_RGBA4444:
		case SCREEN_FORMAT_RGBX4444:
			egl_conf_attr.red_size = 4; 
			egl_conf_attr.green_size = 4; 
			egl_conf_attr.blue_size = 4; 
			egl_conf_attr.alpha_size = 4;
			break;
		case SCREEN_FORMAT_RGBA5551:
		case SCREEN_FORMAT_RGBX5551:
			egl_conf_attr.red_size = 5; 
			egl_conf_attr.green_size = 5; 
			egl_conf_attr.blue_size = 5; 
			egl_conf_attr.alpha_size = 1;
			break;
		case SCREEN_FORMAT_RGB565:
			egl_conf_attr.red_size = 5; 
			egl_conf_attr.green_size = 6; 
			egl_conf_attr.blue_size = 5; 
			egl_conf_attr.alpha_size = 0;
			break;
		case SCREEN_FORMAT_RGB888:
			egl_conf_attr.red_size = 8; 
			egl_conf_attr.green_size = 8; 
			egl_conf_attr.blue_size = 8; 
			egl_conf_attr.alpha_size = 0;
			break;
		case SCREEN_FORMAT_RGBA8888:
		case SCREEN_FORMAT_RGBX8888:
		case SCREEN_FORMAT_BGRA8888:
		case SCREEN_FORMAT_BGRX8888:
			egl_conf_attr.red_size = 8; 
			egl_conf_attr.green_size = 8; 
			egl_conf_attr.blue_size = 8; 
			egl_conf_attr.alpha_size = 8;
			break;
		case SCREEN_FORMAT_RGBA1010102:
		case SCREEN_FORMAT_RGBX1010102:
		case SCREEN_FORMAT_BGRA1010102:
		case SCREEN_FORMAT_BGRX1010102:
			egl_conf_attr.red_size = 10; 
			egl_conf_attr.green_size = 10; 
			egl_conf_attr.blue_size = 10; 
			egl_conf_attr.alpha_size = 2;
			break;
		default:
			// default to RGBA8888
			egl_conf_attr.red_size = 8; 
			egl_conf_attr.green_size = 8; 
			egl_conf_attr.blue_size = 8; 
			egl_conf_attr.alpha_size = 8;
			break;
	}
	
	// Get all available configs
	int egl_num_configs = 0;
	EGLBoolean rc = eglGetConfigs(egl_display, nullptr, 0, &egl_num_configs);
	if (rc != EGL_TRUE || egl_num_configs == 0) {
		ERR_PRINT("eglGetConfigs failed to get number of configs");
		return nullptr;
	}
	
	EGLConfig *egl_configs = (EGLConfig*)malloc(egl_num_configs * sizeof(EGLConfig));
	if (!egl_configs) {
		ERR_PRINT(vformat("could not allocate memory for %d EGL configs", egl_num_configs));
		return nullptr;
	}
	
	rc = eglGetConfigs(egl_display, egl_configs, egl_num_configs, &egl_num_configs);
	if (rc != EGL_TRUE) {
		ERR_PRINT("eglGetConfigs failed to retrieve configs");
		free(egl_configs);
		return nullptr;
	}
	
	// Find the best EGL config using our RGBA values
	EGLConfig choosen_config = nullptr;
	
	for (int i = 0; i < egl_num_configs; i++) {
		EGLint config_red, config_green, config_blue, config_alpha, config_depth, config_stencil;
		EGLint surface_type, renderable_type;
		
		// Get config attributes with error checking
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_RED_SIZE, &config_red)) {
			WARN_PRINT("Failed to get EGL_RED_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_GREEN_SIZE, &config_green)) {
			WARN_PRINT("Failed to get EGL_GREEN_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_BLUE_SIZE, &config_blue)) {
			WARN_PRINT("Failed to get EGL_BLUE_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_ALPHA_SIZE, &config_alpha)) {
			WARN_PRINT("Failed to get EGL_ALPHA_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_DEPTH_SIZE, &config_depth)) {
			WARN_PRINT("Failed to get EGL_DEPTH_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_STENCIL_SIZE, &config_stencil)) {
			WARN_PRINT("Failed to get EGL_STENCIL_SIZE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_SURFACE_TYPE, &surface_type)) {
			WARN_PRINT("Failed to get EGL_SURFACE_TYPE");
			continue;
		}
		if (!eglGetConfigAttrib(egl_display, egl_configs[i], EGL_RENDERABLE_TYPE, &renderable_type)) {
			WARN_PRINT("Failed to get EGL_RENDERABLE_TYPE");
			continue;
		}
		
		// Check if this config matches our desired requirements
		if ((surface_type & EGL_WINDOW_BIT) && 
		    (renderable_type & EGL_OPENGL_ES3_BIT) &&
		    config_red == egl_conf_attr.red_size &&
		    config_green == egl_conf_attr.green_size &&
		    config_blue == egl_conf_attr.blue_size &&
		    config_alpha == egl_conf_attr.alpha_size &&
		    config_depth == 24 &&
		    config_stencil == 8) {
			choosen_config = egl_configs[i];
			break;
		}
	}
	
	// Use the first found configuration if no match
	if (!choosen_config) {
		choosen_config = egl_configs[0];
		WARN_PRINT("No matching EGL config found, using first found configuration");
	}
	
	free(egl_configs);
	return choosen_config;
}

// Creates and caches a GLDisplay. Returns -1 on error.
int GLManagerEGL_Screen::_get_gldisplay_id() {

	// Assuming single display for QNX
	if (displays.size() > 0)
	{
		return 0;
	}

	// We didn't find any, so we'll have to create one, along with its own
	// EGLDisplay and EGLContext.
	GLDisplay new_gldisplay;
	// new_gldisplay.display = p_display;

    int res = screen_create_context(&m_screenContext, SCREEN_APPLICATION_CONTEXT);
    if (0 != res)
    {
        ERR_PRINT("GL EGL screen_create_context() FAILED");
        return -1;
    }

    // screen attributes
	int screenSize[2];
    const int screenUsage   = SCREEN_USAGE_OPENGL_ES2 | SCREEN_USAGE_OPENGL_ES3;
    const int windowBuffers = 2;

    res = screen_create_window(&m_screenWindow, m_screenContext);
    if (0 != res)
    {
        ERR_PRINT("screen_create_window() FAILED");
        return -1;
    }

	res = screen_get_window_property_iv(m_screenWindow, SCREEN_PROPERTY_FORMAT, &m_screenFormat);
    if (0 != res) 
	{
        ERR_PRINT("screen_set_window_property_iv(SCREEN_PROPERTY_FORMAT) FAILED");
        return -1;
    }
	
	res = screen_get_window_property_pv(m_screenWindow, SCREEN_PROPERTY_DISPLAY,
										(void **)&m_screenDisplay);
	if (0 != res)
	{
		ERR_PRINT("screen_window_get_property_pv(display) FAILED");
		return -1;
	}
	
	res = screen_get_display_property_iv(m_screenDisplay, SCREEN_PROPERTY_SIZE, screenSize);
	if (0 != res)
	{
		ERR_PRINT("screen_get_display_property_iv(screenSize) FAILED");
		return -1;
	}
	
	m_detectedScreenSize = Size2i(screenSize[0], screenSize[1]);

    res = screen_set_window_property_iv(m_screenWindow, SCREEN_PROPERTY_FORMAT, &m_screenFormat);
    if (0 != res)
    {
        ERR_PRINT("screen_set_window_property_iv(SCREEN_PROPERTY_FORMAT) FAILED");
        return -1;
    }

    res = screen_set_window_property_iv(m_screenWindow, SCREEN_PROPERTY_USAGE, &screenUsage);
    if (0 != res)
    {
        ERR_PRINT("screen_set_window_property_iv(SCREEN_PROPERTY_USAGE) FAILED");
        return -1;
    }

    res = screen_set_window_property_iv(m_screenWindow, SCREEN_PROPERTY_SIZE, screenSize);
    if (0 != res)
    {
        ERR_PRINT("screen_set_window_property_iv(SCREEN_PROPERTY_SIZE) FAILED");
        return -1;
    }

    res = screen_create_window_buffers(m_screenWindow, windowBuffers);
    if (0 != res)
    {
        ERR_PRINT("screen_create_window_buffers() FAILED");
        return -1;
    }

	/// Further EGL
    new_gldisplay.egl_display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    if (EGL_NO_DISPLAY == new_gldisplay.egl_display)
    {
        ERR_PRINT("eglGetDisplay() FAILED");
        return -1;
    }

	ERR_FAIL_COND_V(eglGetError() != EGL_SUCCESS, -1);

	ERR_FAIL_COND_V_MSG(new_gldisplay.egl_display == EGL_NO_DISPLAY, -1, "Can't create an EGL display.");

	if (!eglInitialize(new_gldisplay.egl_display, nullptr, nullptr)) {
		ERR_FAIL_V_MSG(-1, "Can't initialize an EGL display.");
	}


	if (!eglBindAPI(_get_platform_api_enum())) {
		ERR_FAIL_V_MSG(-1, "OpenGL not supported.");
	}

	Error err = _gldisplay_create_context(new_gldisplay);

	if (err != OK) {
		eglTerminate(new_gldisplay.egl_display);
		ERR_FAIL_V(-1);
	}

	displays.push_back(new_gldisplay);

	// Return the new GLDisplay's ID.
	return displays.size() - 1;
}


Error GLManagerEGL_Screen::_gldisplay_create_context(GLDisplay &p_gldisplay) {

	
	p_gldisplay.egl_config = choose_config(p_gldisplay.egl_display, m_screenFormat);
	
	if (!p_gldisplay.egl_config) {
		ERR_PRINT("No suitable EGL config found");
		return ERR_CANT_CREATE;
	}
	
	Vector<EGLint> context_attribs = _get_platform_context_attribs();
	p_gldisplay.egl_context = eglCreateContext(p_gldisplay.egl_display, p_gldisplay.egl_config, EGL_NO_CONTEXT, (context_attribs.size() > 0) ? context_attribs.ptr() : nullptr);
	ERR_FAIL_COND_V_MSG(p_gldisplay.egl_context == EGL_NO_CONTEXT, ERR_CANT_CREATE, vformat("Can't create an EGL context. Error code: %d", eglGetError()));

	return OK;
}

Error GLManagerEGL_Screen::open_display() {
	int gldisplay_id = _get_gldisplay_id();
	if (gldisplay_id < 0) {
		return ERR_CANT_CREATE;
	} else {
		return OK;
	}
}

int GLManagerEGL_Screen::display_get_native_visual_id(void *p_display) {
	int gldisplay_id = _get_gldisplay_id();
	ERR_FAIL_COND_V(gldisplay_id < 0, ERR_CANT_CREATE);

	GLDisplay gldisplay = displays[gldisplay_id];

	EGLint native_visual_id = -1;

	if (!eglGetConfigAttrib(gldisplay.egl_display, gldisplay.egl_config, EGL_NATIVE_VISUAL_ID, &native_visual_id)) {
		ERR_FAIL_V(-1);
	}

	return native_visual_id;
}

Error GLManagerEGL_Screen::window_create(DisplayServer::WindowID p_window_id, void *p_display, void *p_native_window, int p_width, int p_height) {
	int gldisplay_id = _get_gldisplay_id();
	ERR_FAIL_COND_V(gldisplay_id < 0, ERR_CANT_CREATE);

	GLDisplay &gldisplay = displays[gldisplay_id];

	// In order to ensure a fast lookup, make sure we got enough elements in the
	// windows local vector to use the window id as an index.
	if (p_window_id >= (int)windows.size()) {
		windows.resize(p_window_id + 1);
	}

	GLWindow &glwindow = windows[p_window_id];
	glwindow.gldisplay_id = gldisplay_id;

	// Vector<EGLAttrib> egl_attribs;
	// egl_attribs.push_back(EGL_RENDER_BUFFER);
	// egl_attribs.push_back(EGL_BACK_BUFFER);
	// egl_attribs.push_back(EGL_NONE);
	const EGLint surfaceAttributes[] = {EGL_RENDER_BUFFER, EGL_BACK_BUFFER, EGL_NONE};

	glwindow.egl_surface = eglCreateWindowSurface(gldisplay.egl_display, gldisplay.egl_config, m_screenWindow, surfaceAttributes);

	if (glwindow.egl_surface == EGL_NO_SURFACE) {
		return ERR_CANT_CREATE;
	}

	glwindow.initialized = true;

	window_make_current(p_window_id);

	return OK;
}

void GLManagerEGL_Screen::window_destroy(DisplayServer::WindowID p_window_id) {
	ERR_FAIL_INDEX(p_window_id, (int)windows.size());

	GLWindow &glwindow = windows[p_window_id];

	if (!glwindow.initialized) {
		return;
	} 

	glwindow.initialized = false;

	ERR_FAIL_INDEX(glwindow.gldisplay_id, (int)displays.size());
	GLDisplay &gldisplay = displays[glwindow.gldisplay_id];

	if (glwindow.egl_surface != EGL_NO_SURFACE) {
		eglDestroySurface(gldisplay.egl_display, glwindow.egl_surface);
		glwindow.egl_surface = nullptr;
	}
}

void GLManagerEGL_Screen::release_current() {
	if (!current_window) {
		return;
	}

	GLDisplay &current_display = displays[current_window->gldisplay_id];

	eglMakeCurrent(current_display.egl_display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
}

void GLManagerEGL_Screen::swap_buffers() {		
	if (!current_window) {
		return;
	}

	if (!current_window->initialized) {
		WARN_PRINT("Current OpenGL window is uninitialized!");
		return;
	}

	GLDisplay &current_display = displays[current_window->gldisplay_id];

	eglSwapBuffers(current_display.egl_display, current_window->egl_surface);
}

void GLManagerEGL_Screen::window_make_current(DisplayServer::WindowID p_window_id) {
	if (p_window_id == DisplayServer::INVALID_WINDOW_ID) {
		return;
	}

	GLWindow &glwindow = windows[p_window_id];

	if (&glwindow == current_window || !glwindow.initialized) {
		return;
	}

	current_window = &glwindow;

	GLDisplay &current_display = displays[current_window->gldisplay_id];

	eglMakeCurrent(current_display.egl_display, current_window->egl_surface, current_window->egl_surface, current_display.egl_context);
}

void GLManagerEGL_Screen::set_use_vsync(bool p_use) {
	// We need an active window to get a display to set the vsync.
	if (!current_window) {
		return;
	}

	GLDisplay &disp = displays[current_window->gldisplay_id];

	int swap_interval = p_use ? 1 : 0;

	if (!eglSwapInterval(disp.egl_display, swap_interval)) {
		WARN_PRINT("Could not set V-Sync mode.");
	}

	use_vsync = p_use;
}

bool GLManagerEGL_Screen::is_using_vsync() const {
	return use_vsync;
}

EGLContext GLManagerEGL_Screen::get_context(DisplayServer::WindowID p_window_id) {
	GLWindow &glwindow = windows[p_window_id];

	if (!glwindow.initialized) {
		return EGL_NO_CONTEXT;
	}

	GLDisplay &display = displays[glwindow.gldisplay_id];

	return display.egl_context;
}

EGLDisplay GLManagerEGL_Screen::get_display(DisplayServer::WindowID p_window_id) {
	GLWindow &glwindow = windows[p_window_id];

	if (!glwindow.initialized) {
		return EGL_NO_CONTEXT;
	}

	GLDisplay &display = displays[glwindow.gldisplay_id];

	return display.egl_display;
}

EGLConfig GLManagerEGL_Screen::get_config(DisplayServer::WindowID p_window_id) {
	GLWindow &glwindow = windows[p_window_id];

	if (!glwindow.initialized) {
		return nullptr;
	}

	GLDisplay &display = displays[glwindow.gldisplay_id];

	return display.egl_config;
}

Error GLManagerEGL_Screen::initialize(void *p_native_display) {
	String client_extensions_string = eglQueryString(EGL_NO_DISPLAY, EGL_EXTENSIONS);

	// If the above method fails, we don't support client extensions, so there's nothing to check.
	if (eglGetError() == EGL_SUCCESS) {
		print_verbose(vformat("Extensions: %s", client_extensions_string));
	}

	return OK;
}


GLManagerEGL_Screen::GLManagerEGL_Screen() {
	// Initialize default screen size
	m_detectedScreenSize = Size2i(1920, 1080);
}

GLManagerEGL_Screen::~GLManagerEGL_Screen() {
	for (unsigned int i = 0; i < displays.size(); i++) {
		eglTerminate(displays[i].egl_display);
	}
}

#endif // EGL_ENABLED
