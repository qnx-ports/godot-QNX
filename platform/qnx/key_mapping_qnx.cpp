/**************************************************************************/
/*  key_mapping_qnx.cpp                                                   */
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

#include "key_mapping_qnx.h"

void KeyMappingQNX::initialize() {

    // Symbol keys
    sym_map[KEYCODE_PAUSE] = Key::PAUSE;
    sym_map[KEYCODE_SCROLL_LOCK] = Key::SCROLLLOCK;
    sym_map[KEYCODE_PRINT] = Key::PRINT;
    sym_map[KEYCODE_SYSREQ] = Key::SYSREQ;
    sym_map[KEYCODE_ESCAPE] = Key::ESCAPE;
    sym_map[KEYCODE_BACKSPACE] = Key::BACKSPACE;
    sym_map[KEYCODE_TAB] = Key::TAB;
    sym_map[KEYCODE_BACK_TAB] = Key::BACKTAB;
    sym_map[KEYCODE_RETURN] = Key::ENTER;
    sym_map[KEYCODE_CAPS_LOCK] = Key::CAPSLOCK;
    sym_map[KEYCODE_LEFT_SHIFT] = Key::SHIFT;
    sym_map[KEYCODE_RIGHT_SHIFT] = Key::SHIFT;
    sym_map[KEYCODE_LEFT_CTRL] = Key::CTRL;
    sym_map[KEYCODE_RIGHT_CTRL] = Key::CTRL;
    sym_map[KEYCODE_LEFT_ALT] = Key::ALT;
    sym_map[KEYCODE_RIGHT_ALT] = Key::ALT;
    sym_map[KEYCODE_MENU] = Key::MENU;
    sym_map[KEYCODE_LEFT_HYPER] = Key::HYPER;
    sym_map[KEYCODE_RIGHT_HYPER] = Key::HYPER;
    sym_map[KEYCODE_INSERT] = Key::INSERT;
    sym_map[KEYCODE_HOME] = Key::HOME;
    sym_map[KEYCODE_PG_UP] = Key::PAGEUP;
    sym_map[KEYCODE_DELETE] = Key::KEY_DELETE;
    sym_map[KEYCODE_END] = Key::END;
    sym_map[KEYCODE_PG_DOWN] = Key::PAGEDOWN;
    sym_map[KEYCODE_LEFT] = Key::LEFT;
    sym_map[KEYCODE_RIGHT] = Key::RIGHT;
    sym_map[KEYCODE_UP] = Key::UP;
    sym_map[KEYCODE_DOWN] = Key::DOWN;
    sym_map[KEYCODE_NUM_LOCK] = Key::NUMLOCK;
    sym_map[KEYCODE_KP_PLUS] = Key::KP_ADD;
    sym_map[KEYCODE_KP_MINUS] = Key::KP_SUBTRACT;
    sym_map[KEYCODE_KP_MULTIPLY] = Key::KP_MULTIPLY;
    sym_map[KEYCODE_KP_DIVIDE] = Key::KP_DIVIDE;
    sym_map[KEYCODE_KP_ENTER] = Key::KP_ENTER;
    sym_map[KEYCODE_KP_HOME] = Key::KP_7;
    sym_map[KEYCODE_KP_UP] = Key::KP_8;
    sym_map[KEYCODE_KP_PG_UP] = Key::KP_9;
    sym_map[KEYCODE_KP_LEFT] = Key::KP_4;
    sym_map[KEYCODE_KP_FIVE] = Key::KP_5;
    sym_map[KEYCODE_KP_RIGHT] = Key::KP_6;
    sym_map[KEYCODE_KP_END] = Key::KP_1;
    sym_map[KEYCODE_KP_DOWN] = Key::KP_2;
    sym_map[KEYCODE_KP_PG_DOWN] = Key::KP_3;
    sym_map[KEYCODE_KP_INSERT] = Key::KP_0;
    sym_map[KEYCODE_KP_DELETE] = Key::KP_PERIOD;
    sym_map[KEYCODE_F1] = Key::F1;
    sym_map[KEYCODE_F2] = Key::F2;
    sym_map[KEYCODE_F3] = Key::F3;
    sym_map[KEYCODE_F4] = Key::F4;
    sym_map[KEYCODE_F5] = Key::F5;
    sym_map[KEYCODE_F6] = Key::F6;
    sym_map[KEYCODE_F7] = Key::F7;
    sym_map[KEYCODE_F8] = Key::F8;
    sym_map[KEYCODE_F9] = Key::F9;
    sym_map[KEYCODE_F10] = Key::F10;
    sym_map[KEYCODE_F11] = Key::F11;
    sym_map[KEYCODE_F12] = Key::F12;
    sym_map[KEYCODE_POWER] = Key::STANDBY;
    sym_map[KEYCODE_SLEEP] = Key::STANDBY;
    sym_map[KEYCODE_SLEEP_AFTER] = Key::STANDBY;
    sym_map[KEYCODE_SLEEP_MODE] = Key::STANDBY;
    sym_map[KEYCODE_MENU_PICK] = Key::MENU;
    sym_map[KEYCODE_MENU_UP] = Key::UP;
    sym_map[KEYCODE_MENU_DOWN] = Key::DOWN;
    sym_map[KEYCODE_MENU_LEFT] = Key::LEFT;
    sym_map[KEYCODE_MENU_RIGHT] = Key::RIGHT;
    sym_map[KEYCODE_MENU_ESCAPE] = Key::ESCAPE;
    sym_map[KEYCODE_SNAPSHOT] = Key::PRINT;
    sym_map[KEYCODE_PLAY] = Key::MEDIAPLAY;
    sym_map[KEYCODE_RECORD] = Key::MEDIARECORD;
    sym_map[KEYCODE_FAST_FORWARD] = Key::MEDIANEXT;
    sym_map[KEYCODE_REWIND] = Key::MEDIAPREVIOUS;
    sym_map[KEYCODE_SCAN_NEXT] = Key::MEDIANEXT;
    sym_map[KEYCODE_SCAN_PREVIOUS] = Key::MEDIAPREVIOUS;
    sym_map[KEYCODE_STOP] = Key::MEDIASTOP;
    sym_map[KEYCODE_PLAY_PAUSE] = Key::MEDIAPLAY;
    sym_map[KEYCODE_PLAY_SKIP] = Key::MEDIANEXT;
    sym_map[KEYCODE_MUTE] = Key::VOLUMEMUTE;
    sym_map[KEYCODE_VOLUME_UP] = Key::VOLUMEUP;
    sym_map[KEYCODE_VOLUME_DOWN] = Key::VOLUMEDOWN;
    sym_map[KEYCODE_HELP] = Key::HELP;
    sym_map[KEYCODE_AC_PRINT] = Key::PRINT;
    sym_map[KEYCODE_AC_HOME] = Key::HOMEPAGE;
    sym_map[KEYCODE_AC_BACK] = Key::BACK;
    sym_map[KEYCODE_AC_FORWARD] = Key::FORWARD;
    sym_map[KEYCODE_AC_STOP] = Key::STOP;
    sym_map[KEYCODE_AC_REFRESH] = Key::REFRESH;
    sym_map[KEYCODE_AC_BOOKMARKS] = Key::FAVORITES;
    sym_map[KEYCODE_AC_SEARCH] = Key::SEARCH;
    sym_map[KEYCODE_AC_INSERT_MODE] = Key::INSERT;
    sym_map[KEYCODE_AC_DELETE] = Key::KEY_DELETE;
    sym_map[KEYCODE_AL_EMAIL_READER] = Key::LAUNCHMAIL;
    sym_map[KEYCODE_AL_AV_CAPTURE_PLAYBACK] = Key::LAUNCHMEDIA;
    sym_map[KEYCODE_AL_INTEGRATED_HELP_CENTER] = Key::HELP;
    sym_map[KEYCODE_AL_KEYBOARD_LAYOUT] = Key::KEYBOARD;
    sym_map[KEYCODE_AL_OEM_HELP] = Key::HELP;
    sym_map[KEYCODE_AL_SEARCH_BROWSER] = Key::SEARCH;
    sym_map[KEYCODE_AL_AUDIO_PLAYER] = Key::LAUNCHMEDIA;
    sym_map[KEYCODE_SPACE] = Key::SPACE;
    sym_map[KEYCODE_EXCLAM] = Key::EXCLAM;
    sym_map[KEYCODE_QUOTE] = Key::QUOTEDBL;
    sym_map[KEYCODE_NUMBER] = Key::NUMBERSIGN;
    sym_map[KEYCODE_DOLLAR] = Key::DOLLAR;
    sym_map[KEYCODE_PERCENT] = Key::PERCENT;
    sym_map[KEYCODE_AMPERSAND] = Key::AMPERSAND;
    sym_map[KEYCODE_APOSTROPHE] = Key::APOSTROPHE;
    sym_map[KEYCODE_LEFT_PAREN] = Key::PARENLEFT;
    sym_map[KEYCODE_RIGHT_PAREN] = Key::PARENRIGHT;
    sym_map[KEYCODE_ASTERISK] = Key::ASTERISK;
    sym_map[KEYCODE_PLUS] = Key::PLUS;
    sym_map[KEYCODE_COMMA] = Key::COMMA;
    sym_map[KEYCODE_MINUS] = Key::MINUS;
    sym_map[KEYCODE_PERIOD] = Key::PERIOD;
    sym_map[KEYCODE_SLASH] = Key::SLASH;
    sym_map[KEYCODE_ZERO] = Key::KEY_0;
    sym_map[KEYCODE_ONE] = Key::KEY_1;
    sym_map[KEYCODE_TWO] = Key::KEY_2;
    sym_map[KEYCODE_THREE] = Key::KEY_3;
    sym_map[KEYCODE_FOUR] = Key::KEY_4;
    sym_map[KEYCODE_FIVE] = Key::KEY_5;
    sym_map[KEYCODE_SIX] = Key::KEY_6;
    sym_map[KEYCODE_SEVEN] = Key::KEY_7;
    sym_map[KEYCODE_EIGHT] = Key::KEY_8;
    sym_map[KEYCODE_NINE] = Key::KEY_9;
    sym_map[KEYCODE_COLON] = Key::COLON;
    sym_map[KEYCODE_SEMICOLON] = Key::SEMICOLON;
    sym_map[KEYCODE_LESS_THAN] = Key::LESS;
    sym_map[KEYCODE_EQUAL] = Key::EQUAL;
    sym_map[KEYCODE_GREATER_THAN] = Key::GREATER;
    sym_map[KEYCODE_QUESTION] = Key::QUESTION;
    sym_map[KEYCODE_AT] = Key::AT;
    sym_map[KEYCODE_CAPITAL_A] = Key::A;
    sym_map[KEYCODE_CAPITAL_B] = Key::B;
    sym_map[KEYCODE_CAPITAL_C] = Key::C;
    sym_map[KEYCODE_CAPITAL_D] = Key::D;
    sym_map[KEYCODE_CAPITAL_E] = Key::E;
    sym_map[KEYCODE_CAPITAL_F] = Key::F;
    sym_map[KEYCODE_CAPITAL_G] = Key::G;
    sym_map[KEYCODE_CAPITAL_H] = Key::H;
    sym_map[KEYCODE_CAPITAL_I] = Key::I;
    sym_map[KEYCODE_CAPITAL_J] = Key::J;
    sym_map[KEYCODE_CAPITAL_K] = Key::K;
    sym_map[KEYCODE_CAPITAL_L] = Key::L;
    sym_map[KEYCODE_CAPITAL_M] = Key::M;
    sym_map[KEYCODE_CAPITAL_N] = Key::N;
    sym_map[KEYCODE_CAPITAL_O] = Key::O;
    sym_map[KEYCODE_CAPITAL_P] = Key::P;
    sym_map[KEYCODE_CAPITAL_Q] = Key::Q;
    sym_map[KEYCODE_CAPITAL_R] = Key::R;
    sym_map[KEYCODE_CAPITAL_S] = Key::S;
    sym_map[KEYCODE_CAPITAL_T] = Key::T;
    sym_map[KEYCODE_CAPITAL_U] = Key::U;
    sym_map[KEYCODE_CAPITAL_V] = Key::V;
    sym_map[KEYCODE_CAPITAL_W] = Key::W;
    sym_map[KEYCODE_CAPITAL_X] = Key::X;
    sym_map[KEYCODE_CAPITAL_Y] = Key::Y;
    sym_map[KEYCODE_CAPITAL_Z] = Key::Z;
    sym_map[KEYCODE_LEFT_BRACKET] = Key::BRACKETLEFT;
    sym_map[KEYCODE_BACK_SLASH] = Key::BACKSLASH;
    sym_map[KEYCODE_RIGHT_BRACKET] = Key::BRACKETRIGHT;
    sym_map[KEYCODE_CIRCUMFLEX] = Key::ASCIICIRCUM;
    sym_map[KEYCODE_UNDERSCORE] = Key::UNDERSCORE;
    sym_map[KEYCODE_GRAVE] = Key::QUOTELEFT;
    sym_map[KEYCODE_A] = Key::A;
    sym_map[KEYCODE_B] = Key::B;
    sym_map[KEYCODE_C] = Key::C;
    sym_map[KEYCODE_D] = Key::D;
    sym_map[KEYCODE_E] = Key::E;
    sym_map[KEYCODE_F] = Key::F;
    sym_map[KEYCODE_G] = Key::G;
    sym_map[KEYCODE_H] = Key::H;
    sym_map[KEYCODE_I] = Key::I;
    sym_map[KEYCODE_J] = Key::J;
    sym_map[KEYCODE_K] = Key::K;
    sym_map[KEYCODE_L] = Key::L;
    sym_map[KEYCODE_M] = Key::M;
    sym_map[KEYCODE_N] = Key::N;
    sym_map[KEYCODE_O] = Key::O;
    sym_map[KEYCODE_P] = Key::P;
    sym_map[KEYCODE_Q] = Key::Q;
    sym_map[KEYCODE_R] = Key::R;
    sym_map[KEYCODE_S] = Key::S;
    sym_map[KEYCODE_T] = Key::T;
    sym_map[KEYCODE_U] = Key::U;
    sym_map[KEYCODE_V] = Key::V;
    sym_map[KEYCODE_W] = Key::W;
    sym_map[KEYCODE_X] = Key::X;
    sym_map[KEYCODE_Y] = Key::Y;
    sym_map[KEYCODE_Z] = Key::Z;
    sym_map[KEYCODE_LEFT_BRACE] = Key::BRACELEFT;
    sym_map[KEYCODE_BAR] = Key::BAR;
    sym_map[KEYCODE_RIGHT_BRACE] = Key::BRACERIGHT;
    sym_map[KEYCODE_TILDE] = Key::ASCIITILDE;
    sym_map[KEYCODE_NO_BREAK_SPACE] = Key::SPACE;
    sym_map[KEYCODE_INVERTED_EXCLAMATION_MARK] = Key::EXCLAM;
    sym_map[KEYCODE_YEN_SIGN] = Key::YEN;
    sym_map[KEYCODE_BROKEN_BAR] = Key::BAR;
    sym_map[KEYCODE_SECTION_SIGN] = Key::SECTION;
    sym_map[KEYCODE_SOFT_HYPHEN] = Key::MINUS;
    sym_map[KEYCODE_MIDDLE_DOT] = Key::PERIOD;
    sym_map[KEYCODE_INVERTED_QUESTION_MARK] = Key::QUESTION;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_GRAVE] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_ACUTE] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_TILDE] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_DIAERESIS] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_A_WITH_RING_ABOVE] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LIGATURE_AE] = Key::A;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_C_WITH_CEDILLA] = Key::C;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_E_WITH_GRAVE] = Key::E;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_E_WITH_ACUTE] = Key::E;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX] = Key::E;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_E_WITH_DIAERESIS] = Key::E;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_I_WITH_GRAVE] = Key::I;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_I_WITH_ACUTE] = Key::I;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX] = Key::I;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS] = Key::I;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_N_WITH_TILDE] = Key::N;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_GRAVE] = Key::O;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_ACUTE] = Key::O;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX] = Key::O;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_TILDE] = Key::O;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_DIAERESIS] = Key::O;
    sym_map[KEYCODE_MULTIPLICATION_SIGN] = Key::ASTERISK;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_O_WITH_STROKE] = Key::O;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_U_WITH_GRAVE] = Key::U;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_U_WITH_ACUTE] = Key::U;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX] = Key::U;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_U_WITH_DIAERESIS] = Key::U;
    sym_map[KEYCODE_LATIN_CAPITAL_LETTER_Y_WITH_ACUTE] = Key::Y;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_SHARP_S] = Key::S;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_GRAVE] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_ACUTE] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_TILDE] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_DIAERESIS] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_A_WITH_RING_ABOVE] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LIGATURE_AE] = Key::A;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_C_WITH_CEDILLA] = Key::C;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_E_WITH_GRAVE] = Key::E;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_E_WITH_ACUTE] = Key::E;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX] = Key::E;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_E_WITH_DIAERESIS] = Key::E;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_I_WITH_GRAVE] = Key::I;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_I_WITH_ACUTE] = Key::I;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX] = Key::I;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_I_WITH_DIAERESIS] = Key::I;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_N_WITH_TILDE] = Key::N;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_GRAVE] = Key::O;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_ACUTE] = Key::O;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX] = Key::O;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_TILDE] = Key::O;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_DIAERESIS] = Key::O;
    sym_map[KEYCODE_DIVISION_SIGN] = Key::SLASH;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_O_WITH_STROKE] = Key::O;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_U_WITH_GRAVE] = Key::U;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_U_WITH_ACUTE] = Key::U;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX] = Key::U;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_U_WITH_DIAERESIS] = Key::U;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_Y_WITH_ACUTE] = Key::Y;
    sym_map[KEYCODE_LATIN_SMALL_LETTER_Y_WITH_DIAERESIS] = Key::Y;

    // Physical keys
    scan_map[KS_a] = Key::A;
    scan_map[KS_b] = Key::B;
    scan_map[KS_c] = Key::C;
    scan_map[KS_d] = Key::D;
    scan_map[KS_e] = Key::E;
    scan_map[KS_f] = Key::F;
    scan_map[KS_g] = Key::G;
    scan_map[KS_h] = Key::H;
    scan_map[KS_i] = Key::I;
    scan_map[KS_j] = Key::J;
    scan_map[KS_k] = Key::K;
    scan_map[KS_l] = Key::L;
    scan_map[KS_m] = Key::M;
    scan_map[KS_n] = Key::N;
    scan_map[KS_o] = Key::O;
    scan_map[KS_p] = Key::P;
    scan_map[KS_q] = Key::Q;
    scan_map[KS_r] = Key::R;
    scan_map[KS_s] = Key::S;
    scan_map[KS_t] = Key::T;
    scan_map[KS_u] = Key::U;
    scan_map[KS_v] = Key::V;
    scan_map[KS_w] = Key::W;
    scan_map[KS_x] = Key::X;
    scan_map[KS_y] = Key::Y;
    scan_map[KS_z] = Key::Z;
    scan_map[KS_1] = Key::KEY_1;
    scan_map[KS_2] = Key::KEY_2;
    scan_map[KS_3] = Key::KEY_3;
    scan_map[KS_4] = Key::KEY_4;
    scan_map[KS_5] = Key::KEY_5;
    scan_map[KS_6] = Key::KEY_6;
    scan_map[KS_7] = Key::KEY_7;
    scan_map[KS_8] = Key::KEY_8;
    scan_map[KS_9] = Key::KEY_9;
    scan_map[KS_0] = Key::KEY_0;
    scan_map[KS_Enter] = Key::ENTER;
    scan_map[KS_Escape] = Key::ESCAPE;
    scan_map[KS_BackSpace] = Key::BACKSPACE;
    scan_map[KS_Tab] = Key::TAB;
    scan_map[KS_space] = Key::SPACE;
    scan_map[KS_minus] = Key::MINUS;
    scan_map[KS_equal] = Key::EQUAL;
    scan_map[KS_bracketleft] = Key::BRACKETLEFT;
    scan_map[KS_bracketright] = Key::BRACKETRIGHT;
    scan_map[KS_backslash] = Key::BACKSLASH;
    scan_map[KS_semicolon] = Key::SEMICOLON;
    scan_map[KS_apostrophe] = Key::APOSTROPHE;
    scan_map[KS_grave] = Key::QUOTELEFT;
    scan_map[KS_comma] = Key::COMMA;
    scan_map[KS_period] = Key::PERIOD;
    scan_map[KS_slash] = Key::SLASH;
    scan_map[KS_Caps_Lock] = Key::CAPSLOCK;
    scan_map[KS_f1] = Key::F1;
    scan_map[KS_f2] = Key::F2;
    scan_map[KS_f3] = Key::F3;
    scan_map[KS_f4] = Key::F4;
    scan_map[KS_f5] = Key::F5;
    scan_map[KS_f6] = Key::F6;
    scan_map[KS_f7] = Key::F7;
    scan_map[KS_f8] = Key::F8;
    scan_map[KS_f9] = Key::F9;
    scan_map[KS_f10] = Key::F10;
    scan_map[KS_f11] = Key::F11;
    scan_map[KS_f12] = Key::F12;
    scan_map[KS_Print_Screen] = Key::PRINT;
    scan_map[KS_Hold_Screen] = Key::SCROLLLOCK;
    scan_map[KS_Pause] = Key::PAUSE;
    scan_map[KS_Insert] = Key::INSERT;
    scan_map[KS_Home] = Key::HOME;
    scan_map[KS_PgUp] = Key::PAGEUP;
    scan_map[KS_Delete] = Key::KEY_DELETE;
    scan_map[KS_End] = Key::END;
    scan_map[KS_PgDn] = Key::PAGEDOWN;
    scan_map[KS_Right] = Key::RIGHT;
    scan_map[KS_Left] = Key::LEFT;
    scan_map[KS_Down] = Key::DOWN;
    scan_map[KS_Up] = Key::UP;
    scan_map[KS_Num_Lock] = Key::NUMLOCK;
    scan_map[KS_KP_Divide] = Key::KP_DIVIDE;
    scan_map[KS_KP_Multiply] = Key::KP_MULTIPLY;
    scan_map[KS_KP_Subtract] = Key::KP_SUBTRACT;
    scan_map[KS_KP_Add] = Key::KP_ADD;
    scan_map[KS_KP_Enter] = Key::KP_ENTER;
    scan_map[KS_KP_1] = Key::KP_1;
    scan_map[KS_KP_2] = Key::KP_2;
    scan_map[KS_KP_3] = Key::KP_3;
    scan_map[KS_KP_4] = Key::KP_4;
    scan_map[KS_KP_5] = Key::KP_5;
    scan_map[KS_KP_6] = Key::KP_6;
    scan_map[KS_KP_7] = Key::KP_7;
    scan_map[KS_KP_8] = Key::KP_8;
    scan_map[KS_KP_9] = Key::KP_9;
    scan_map[KS_KP_0] = Key::KP_0;
    scan_map[KS_KP_Delete] = Key::KP_PERIOD;
    scan_map[KS_NonUSSlash] = Key::BACKSLASH;
    scan_map[KS_Application] = Key::MENU;
    scan_map[KS_Keypad_Eq] = Key::EQUAL;
    scan_map[KS_f13] = Key::F13;
    scan_map[KS_f14] = Key::F14;
    scan_map[KS_f15] = Key::F15;
    scan_map[KS_f16] = Key::F16;
    scan_map[KS_f17] = Key::F17;
    scan_map[KS_f18] = Key::F18;
    scan_map[KS_f19] = Key::F19;
    scan_map[KS_f20] = Key::F20;
    scan_map[KS_f21] = Key::F21;
    scan_map[KS_f22] = Key::F22;
    scan_map[KS_f23] = Key::F23;
    scan_map[KS_f24] = Key::F24;
    scan_map[KS_Help] = Key::HELP;
    scan_map[KS_Stop] = Key::STOP;
    scan_map[KS_Mute] = Key::VOLUMEMUTE;
    scan_map[KS_Volume_Up] = Key::VOLUMEUP;
    scan_map[KS_Volume_Down] = Key::VOLUMEDOWN;
    scan_map[KS_LockCpsLock] = Key::CAPSLOCK;
    scan_map[KS_LockNumLock] = Key::NUMLOCK;
    scan_map[KS_LockScrLock] = Key::SCROLLLOCK;
    scan_map[KS_KP_Comma] = Key::COMMA;
    scan_map[KS_KP_Equal] = Key::EQUAL; 
    scan_map[KS_SysReq] = Key::SYSREQ;
    scan_map[KS_Clear] = Key::CLEAR;
    scan_map[KS_Control_L] = Key::CTRL;  // LCtrl
    scan_map[KS_Shift_L] = Key::SHIFT;   // LShift
    scan_map[KS_Alt_L] = Key::ALT;       // LAlt
    scan_map[KS_LeftGUI] = Key::META;    // LGUI
    scan_map[KS_Control_R] = Key::CTRL;  // RCtrl
    scan_map[KS_Shift_R] = Key::SHIFT;   // RShift
    scan_map[KS_Alt_R] = Key::ALT;       // RAlt
    scan_map[KS_RightGUI] = Key::META;   // RGUI

    // Locations
    location_map[KS_Control_L] = KeyLocation::LEFT;
    location_map[KS_Shift_L] = KeyLocation::LEFT;
    location_map[KS_Alt_L] = KeyLocation::LEFT;
    location_map[KS_LeftGUI] = KeyLocation::LEFT;
    location_map[KS_Control_R] = KeyLocation::RIGHT;
    location_map[KS_Shift_R] = KeyLocation::RIGHT;
    location_map[KS_Alt_R] = KeyLocation::RIGHT;
    location_map[KS_RightGUI] = KeyLocation::RIGHT;
}

Key KeyMappingQNX::get_keycode(int p_sym) {
    const Key *key = sym_map.getptr(p_sym);
    if (key) {
		return *key;
	}
	return Key::NONE;
}

Key KeyMappingQNX::get_scancode(unsigned int p_scan) {
    const Key *key = scan_map.getptr(p_scan);
    if (key) {
		return *key;
	}
	return Key::NONE;
}

char32_t KeyMappingQNX::get_unicode(unsigned int p_cap) {
    return p_cap;
}

KeyLocation KeyMappingQNX::get_location(unsigned int p_scan) {
    const KeyLocation *location = location_map.getptr(p_scan);
    if (location) {
		return *location;
	}
	return KeyLocation::UNSPECIFIED;
}


