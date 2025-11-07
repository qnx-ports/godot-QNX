/**************************************************************************/
/*  key_mapping_qnx.h                                                     */
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

#ifndef KEY_MAPPING_QNX_H
#define KEY_MAPPING_QNX_H

#include "core/os/keyboard.h"
#include "core/templates/hash_map.h"
#include <sys/keycodes.h>
#include <sys/usbcodes.h>

class KeyMappingQNX {
    struct HashMapHasherKeys {
        static _FORCE_INLINE_ uint32_t hash(const Key p_key) { return hash_fmix32(static_cast<uint32_t>(p_key)); }
        static _FORCE_INLINE_ uint32_t hash(const char32_t p_uchar) { return hash_fmix32(p_uchar); }
        static _FORCE_INLINE_ uint32_t hash(const unsigned p_key) { return hash_fmix32(p_key); }
        static _FORCE_INLINE_ uint32_t hash(const int p_key) { return hash_fmix32(static_cast<uint32_t>(p_key)); }
    };

    static inline HashMap<int, Key, HashMapHasherKeys> sym_map;
    static inline HashMap<unsigned int, Key, HashMapHasherKeys> scan_map;
    static inline HashMap<unsigned int, KeyLocation, HashMapHasherKeys> location_map;

    KeyMappingQNX() {}
public:
    static void initialize();

    static Key get_keycode(int p_sym);
    static Key get_scancode(unsigned int p_scan);
    static char32_t get_unicode(unsigned int p_cap);
    static KeyLocation get_location(unsigned int p_scan);
};

#endif // KEY_MAPPING_QNX_H


