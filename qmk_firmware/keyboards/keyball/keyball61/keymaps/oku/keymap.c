/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_ESC        , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
    KC_TAB        , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_LCTL       , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  ,KC_QUOT,
    LM(1,MOD_LSFT), KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC  ,              KC_NUHS, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_INT1 ,
    KC_LSFT       , KC_INT3  , KC_LGUI  , KC_LALT  , KC_SPC   , MO(2)    ,LT(3,KC_LNG1),  LT(2,KC_SPC),KC_BSPC     ,  _______ , _______  , _______  ,  KC_EQL  , KC_ENT 
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______ , _______  , _______  ,                                  _______  , _______  , _______ , _______ , S(KC_INT3) , _______ ,
    _______  , _______  , _______  , _______ , _______  , _______  ,                                   _______ , _______  , _______ , _______  , _______ , _______  ,
    _______  , _______  , _______  , _______ , _______  , _______  ,                                  _______  , _______  , _______ , _______ , _______, _______  ,
    _______  , _______  , _______  , _______ , _______  , _______  , _______ ,              _______ , _______  , _______  , _______ , _______ , _______ ,_______,
    _______  , _______  , _______  , _______ , _______  , _______  , _______  ,            _______  ,  KC_DEL  , _______  , _______ , _______  ,_______, _______
  ),

  [2] = LAYOUT_universal(
    _______  , KC_F1    , KC_F2     , KC_F3    , KC_F4   , KC_F5    ,                                 KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
    _______  , KC_PSLS  , KC_7      , KC_8     , KC_9   , KC_PMNS  ,                                  _______  , _______  , _______  , _______  , _______  , KC_F12   ,
    _______  , KC_PAST  , KC_4      , KC_5     , KC_6    ,KC_PPLS	 ,                                  KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_PSCR  ,
    _______  , KC_DOT  ,  KC_1      , KC_2     , KC_3   ,KC_ENT    , S(KC_8),               S(KC_9) , KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
    _______  , _______  , KC_0     , _______ , _______  , _______  , _______  ,             _______  , KC_ENT  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , KC_DEL  ,
    RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
    RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
    _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
    QK_BOOT  , _______  , KC_LEFT  , KC_RGHT  , KC_DOWN  , KC_UP  , _______  ,            KC_LNG2  ,    KC_DEL  , _______  , _______  , _______  , _______  , QK_BOOT
  ),
  // Below map is for when keyboard is set to US layout (and out of date)
  // [0] = LAYOUT_universal(
  //   KC_ESC        , KC_1     , KC_2     , KC_3     , KC_4     , KC_5     ,                                  KC_6     , KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  ,
  //   KC_TAB        , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , S(KC_2) ,
  //   KC_LCTL       , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     , KC_SCLN  ,S(KC_SCLN),
  //   LM(1,MOD_LSFT), KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_LBRC  ,              KC_RBRC, KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_BSLS  ,
  //   KC_LSFT       , KC_NUBS  , KC_LGUI  , KC_LALT  , KC_SPC   ,LT(2,KC_SPC),LT(3,KC_LNG1),  LT(2,KC_SPC),KC_BSPC     ,LT(1,KC_LNG2), _______, _______ ,  S(KC_6) , KC_ENT 
  // ),

  // [1] = LAYOUT_universal(
  //   _______  , _______  , S(KC_QUOT), _______ , _______  , _______  ,                                  S(KC_7)  , KC_QUOT  ,S(KC_9)   , S(KC_0), KC_NUBS , KC_EQL ,
  //   _______  , _______  , _______  , _______ , _______  , _______  ,                                   _______ , _______ , _______  , _______  , _______  , KC_GRV  ,
  //   _______  , _______  , _______  , _______ , _______  , _______  ,                                  _______  , _______  , _______ , _______ , S(KC_EQL), S(KC_8)  ,
  //   _______  , _______  , _______  , _______ , _______  , _______  , _______ ,              _______ , _______  , _______  , _______ , _______ , _______ ,S(KC_MINS),
  //   _______  , _______  , _______  , _______ , _______  , _______  , _______  ,            _______  ,  KC_DEL  , _______  , _______ , _______  , S(KC_GRV), _______
  // ),

  // [2] = LAYOUT_universal(
  //   _______  , KC_F1    , KC_F2     , KC_F3    , KC_F4   , KC_F5    ,                                  KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   ,
  //   _______  , KC_PSLS  , KC_P7     , KC_P8    , KC_P9   , KC_PMNS  ,                                  _______  , _______  , _______  , _______  , _______  , KC_F12   ,
  //   _______  , KC_PAST  , KC_P4     , KC_P5    , KC_P6   ,KC_PPLS	 ,                                  KC_PGUP  , KC_BTN1  , KC_UP    , KC_BTN2  , KC_BTN3  , KC_PSCR  ,
  //   _______  , KC_DOT  ,  KC_P1     , KC_P2    , KC_P3   ,KC_EQL    , S(KC_9),              S(KC_0) , KC_PGDN  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,
  //   _______  , _______  , KC_P0     , _______ , _______  , _______  , _______  ,             _______  , KC_ENT  , _______  , _______  , _______  , _______  , _______
  // ),

  // [3] = LAYOUT_universal(
  //   RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                  RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
  //   RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , _______  ,                                  RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
  //   RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , _______  ,                                  CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , KBC_SAVE , KBC_RST  ,
  //   _______  , _______  , SCRL_DVD , SCRL_DVI , SCRL_MO  , SCRL_TO  , EE_CLR   ,            EE_CLR   , KC_HOME  , KC_PGDN  , KC_PGUP  , KC_END   , _______  , _______  ,
  //   QK_BOOT  , _______  , KC_LEFT  , KC_RGHT  , KC_DOWN  , KC_UP  , _______  ,            KC_LNG2  , _______  , _______  , _______  , _______  , _______  , QK_BOOT
  // ),
};
// clang-format on

// // key overrides 
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DEL, KC_DEL);
// const key_override_t grave_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_GRV, KC_GRV);
// const key_override_t quote_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUOT, KC_QUOT);
// const key_override_t equal_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_EQL, KC_EQL);

// // This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&delete_key_override,
	// &grave_key_override,
	// &quote_key_override,
	// &equal_key_override,
	NULL // Null terminate the array of overrides!
};

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);

    // // レイヤーとLEDを連動させる
    // uint8_t layer = biton32(state);
    // switch (layer)
    // {
    // case 4:
    //     //rgblight_sethsv(HSV_WHITE);
    //     rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    //   break;

    // default:
    //   //rgblight_sethsv(HSV_OFF);
    //   rgb_matrix_reload_from_eeprom();
    // }

    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}

#endif

bool led_update_user(led_t led_state) {
	if (!led_state.num_lock) {
		tap_code(KC_NUM_LOCK);
	}
	return true;
}

// led_config_t g_led_config = { {
//   // Key Matrix to LED Index
  /*
  {24, 19, 14,  9,  5,  1,            66,     62,     58,     54, 49, 44}, \
  {25, 20, 15, 10,  6,  2,            67,     63,     59,     55, 50, 45}, \
  {26, 21, 16, 11,  7,  3,            68,     64,     60,     56, 51, 46}, \
  {27, 22, 17, 12,  8,  4,  0,    70, 69,     65,     61,     57, 52, 47}, \
  {28, 23, 18, 13, 34, 35, 36,    37, 38, NO_LED, NO_LED, NO_LED, 53, 48} \ 
  // {29, 30, 31 ,32, 33,                    39, 40, 41, 42, 43}   //underglows 
  */
//   {24, 19,     14, NO_LED,      9,      5,  1, NO_LED}, 
//   {25, 20,     15, NO_LED,     10,      6,  2, NO_LED}, 
//   {26, 21,     16, NO_LED,     11,      7,  3, NO_LED}, 
//   {27, 22,     17, NO_LED,     12,      8,  4,      0}, 
//   {28, 23,     18, NO_LED,     13,     34, 35,     36}, 
//   {44, 49,     54, NO_LED,     58,     62, 66, NO_LED}, 
//   {45, 50,     55, NO_LED,     59,     63, 67, NO_LED}, 
//   {46, 51,     56, NO_LED,     60,     64, 68, NO_LED}, 
//   {47, 52,     57, NO_LED,     61,     65, 69,     70}, 
//   {48, 53, NO_LED, NO_LED, NO_LED, NO_LED, 38,     37} 
// }, {
//   // LED Index to Physical Position
//   // {x,y}: x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION , y =  64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
// {84,48}	, //0
// {70,0}	, //1
// {70,16}	, //2
// {70,32}	, //3
// {70,48}	, //4
// {56,0}	, //5
// {56,16}	, //6
// {56,32}	, //7
// {56,48}	, //8
// {42,0}	, //9
// {42,16}	, //10
// {42,32}	, //11
// {42,48}	, //12
// {42,64}	, //13
// {28,0}	, //14
// {28,16}	, //15
// {28,32}	, //16
// {28,48}	, //17
// {28,64}	, //18
// {14,0}	, //19
// {14,16}	, //20
// {14,32}	, //21
// {14,48}	, //22
// {14,64}	, //23
// {0,0}	, //24
// {0,16}	, //25
// {0,32}	, //26
// {0,48}	, //27
// {0,64}	, //28
// {0,0}	, //29
// {0,0}	, //30
// {0,0}	, //31
// {0,0}	, //32
// {0,0}	, //33
// {56,64}	, //34
// {70,64}	, //35
// {84,64}	, //36
// {126,64}	, //37
// {140,64}	, //38
// {0,0}	, //39
// {0,0}	, //40
// {0,0}	, //41
// {0,0}	, //42
// {0,0}	, //43
// {210,0}	, //44
// {210,16}	, //45
// {210,32}	, //46
// {210,48}	, //47
// {210,64}	, //48
// {196,0}	, //49
// {196,16}	, //50
// {196,32}	, //51
// {196,48}	, //52
// {196,64}	, //53
// {182,0}	, //54
// {182,16}	, //55
// {182,32}	, //56
// {182,48}	, //57
// {168,0}	, //58
// {168,16}	, //59
// {168,32}	, //60
// {168,48}	, //61
// {154,0}	, //62
// {154,16}	, //63
// {154,32}	, //64
// {154,48}	, //65
// {140,0}	, //66
// {140,16}	, //67
// {140,32}	, //68
// {140,48}	/*, //69
// {126,48}	, //70

// {0,0}	, //71
// {0,0}	, //72
// {0,0}	, //73
// */
// }, {
//   // LED Index to Flag
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	,
// LED_FLAG_KEYLIGHT	/*,
// LED_FLAG_KEYLIGHT ,
// LED_FLAG_NONE	,
// LED_FLAG_NONE	,
// LED_FLAG_NONE		*/
// } };

// void keyboard_post_init_user(void) {
//   // Call the post init code.
//   rgb_matrix_reload_from_eeprom();
// }
