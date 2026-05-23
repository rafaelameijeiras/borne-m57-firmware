#include QMK_KEYBOARD_H

#include "quantum.h"

#include "hal_pal.h"

enum layers {
  _QWERTY,
  _GAME,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
  _MOV,
};


#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define NUM MO(_NUM)
#define SPCMOV LT(_MOV, KC_SPC)
#define TABNUM LT(_NUM, KC_TAB)
#define LTDGUI RGUI_T(KC_A)
#define LTDALT ALT_T(KC_S)
#define LTDSHIT SFT_T(KC_D)
#define LTDCTRL CTL_T(KC_F)
#define RTDGUI RGUI_T(KC_SCLN)
#define RTDALT RALT_T(KC_L)
#define RTDSHIT SFT_T(KC_K)
#define RTDCTRL CTL_T(KC_J)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
   //--------------------------------Left Hand--------------------| |--------------------------------Right Hand------------------------------------------------

      KC_GRV,         KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
      TABNUM,         KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,  KC_UP,       KC_LEFT,  KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      LCTL_T(KC_ESC), LTDGUI, LTDALT, LTDSHIT, LTDCTRL, KC_G,  KC_DOWN,     KC_RIGHT, KC_H,  RTDCTRL, RTDSHIT, RTDALT, RTDGUI,  KC_ENT, 
      KC_LSFT,        KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,  KC_MUTE,     RGB_MOD,  KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, MEH_T(KC_ENT),                                        SPCMOV , RAISE, KC_RALT

  ),
  [_GAME] = LAYOUT(
      KC_ESC,          KC_1,   KC_2,   KC_3,    KC_4,    KC_5,                         KC_6,  KC_7,    KC_8,    KC_9,   KC_0,    KC_DEL,
      KC_TAB,          KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,  KC_INS,      KC_LEFT,  KC_Y,  KC_U,    KC_I,    KC_O,   KC_P,    KC_BSPC,
      LCTL_T(KC_CAPS), KC_A,   KC_S,   KC_D,    KC_F,    KC_G,  KC_PSCR,     KC_RIGHT, KC_H,  KC_J,    KC_K,    KC_L,   KC_SCLN, KC_ENT, 
      KC_LSFT,         KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,  KC_MUTE,     RGB_MOD,  KC_N,  KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, KC_SPC,                                            SPCMOV , RAISE, KC_RALT
  ),

  [_LOWER] = LAYOUT(
      KC_ESC,   KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,                             KC_F6,   KC_F7,   KC_F8,    KC_F9,   KC_F10,  KC_BSPC,
      KC_GRV,   KC_1,    KC_2,       KC_3,       KC_4,       KC_5 ,   KC_F11,         KC_F11,   KC_6,    KC_7,    KC_8,     KC_9,    KC_0,    KC_DEL ,
      _______,  KC_LGUI, KC_LALT,    KC_LSFT,    KC_LCTL,    _______, KC_F12,         KC_F12,   KC_BSLS, KC_MINS , KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,
      _______,  _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, QK_BOOT,        QK_BOOT,  _______, _______ , _______, _______, _______, _______,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, MEH_T(KC_ENT),                                        SPCMOV , MO(_ADJUST), KC_RALT
  ),

  [_RAISE] = LAYOUT(
      KC_ESC,   KC_F1,   KC_F2,      KC_F3,      KC_F4,      KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC,
      KC_TILD , KC_EXLM, KC_AT,      KC_HASH,    KC_DLR,     KC_PERC, KC_F11,         KC_F11,  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
      _______ , KC_LGUI, KC_LALT,    KC_LSFT,    KC_LCTL,    _______, KC_F12,         KC_F12,  KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_DQUO,
      _______,  _______, LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, QK_BOOT,        QK_BOOT, _______, _______, _______, _______, _______, _______ ,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,MO(_ADJUST), MEH_T(KC_ENT),                                        SPCMOV , RAISE, KC_RALT
  ),

  [_ADJUST] = LAYOUT(
      XXXXXXX, XXXXXXX,       XXXXXXX,   XXXXXXX,XXXXXXX,  XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, PDF(_QWERTY),  DF(_GAME), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX, KC_VOLD, KC_MPLY, KC_VOLU, KC_MUTE, XXXXXXX,
      XXXXXXX, XXXXXXX,       XXXXXXX,   XXXXXXX, MS_BTN1, MS_BTN2,  XXXXXXX,     XXXXXXX,  MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX,       XXXXXXX,   XXXXXXX, MS_BTN3, MS_BTN3,  XXXXXXX,     XXXXXXX,  MS_ACL0, MS_ACL1, MS_ACL2, XXXXXXX, XXXXXXX, XXXXXXX,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, MEH_T(KC_ENT),                                        SPCMOV , RAISE, KC_RALT

  ),
  [_NUM] = LAYOUT(
      XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,
      XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  KC_UP,       KC_LEFT,  KC_PAST, KC_7,     KC_8,     KC_9,     KC_PPLS,    KC_DEL,
      XXXXXXX, KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,  KC_DOWN,     KC_RIGHT, KC_DOT,  KC_4,     KC_5,     KC_6,     KC_PMNS,    _______, 
      XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  KC_MUTE,     RGB_MOD,  KC_0,    KC_1,     KC_2,     KC_3,     KC_SLSH,    _______,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, MEH_T(KC_ENT),                                        SPCMOV , RAISE, KC_RALT

  ),
  [_MOV] = LAYOUT(
      XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,                         XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,
      XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,  KC_UP,       KC_LEFT,  KC_INS,  KC_PGDN,  KC_PGUP,  XXXXXXX,  S(KC_INS), KC_PSCR,
      XXXXXXX, KC_LGUI,    KC_LALT,    KC_LSFT,    KC_LCTL,    XXXXXXX,  KC_DOWN,     KC_RIGHT, KC_LEFT, KC_DOWN,  KC_UP,    KC_RIGHT, KC_DEL,    _______, 
      KC_CAPS, _______,    LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______,  KC_MUTE,     RGB_MOD,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,   XXXXXXX,   _______,
      //__________________________________________________________________________________________________________________________________________________________________
                              KC_LGUI,LOWER, MEH_T(KC_ENT),                                        SPCMOV , RAISE, KC_RALT

  ),

};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY]  =   { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_GAME]    =   { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_LOWER]   =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    [_RAISE]   =   { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST]  =   { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
    [_MOV]     =   { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NUM]     =   { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),          ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    //                       Encoder 1                                     Encoder 2
};
#endif
