#include QMK_KEYBOARD_H
#include "version.h"

#include "ergodox_ez.h"
#include "../../shared/colors/layers.c"
#include "../../shared/layouts/setup.c"
#include "../../shared/keycodes/custom_keycodes.c"
#include "../../shared/keycodes/aliases.c"
#include "../../shared/user/store_active_layer.c"
#include "../../shared/user/swap_keys.c"
#include "../../shared/tap_dance/tap_dance_setup.c"
#include "../../shared/tap_dance/tap_dances.c"
#include "../../shared/tap_dance/mod_tap_layer_dances/lalt_pipe.c"
#include "../../shared/tap_dance/tap_dance_actions.c"
#include "../../shared/user/layout_switcher.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [DV] = LAYOUT_ergodox(
      // left hand
      _______,   _______,   KC_AMPR,    KC_PERC,  KC_AT,  KC_LBRC,  _______,
      LALTP,     DQUO_QUOT, NUMS_COMM,  ARR_DOT,  KC_P,   KC_Y,     KC_LPRN,
      LCTL_EQL,  KC_A,      KC_O,       KC_E,     KC_U,   KC_I,
      LSFT_CAPS, COLN_SCLN, KC_Q,       KC_J,     KC_K,   KC_X,     KC_LCBR,
      _______,   _______,   KC_TILD,    KC_DLR,   _______,

                                                                  KC_LGUI,  OSL(4),    _______,
                                                                  KC_SPACE, KC_BSPACE, _______,




                                                            // right hand
                                                            _______,  KC_RBRC,  KC_ASTR,  KC_HASH,    KC_EXLM,  _______, KC_DELETE,
                                                            KC_RPRN,  KC_F,     KC_G,     KC_C,       KC_R,     KC_L,    RALT_SLSH,
                                                                      KC_D,     KC_H,     KC_T,       KC_N,     KC_S,    RCTL_MINS,
                                                            KC_RCBR,  KC_B,     KC_M,     KC_W,       KC_V,     KC_Z,    RSFT_TAB,
                                                                                _______,  KC_CIRC,    KC_GRAVE, KC_INS,  _______,

                                              KC_PSCREEN,   UKR_QWERT, _______,
                                              _______, KC_ESCAPE, KC_ENTER
                      ),

  [QW] = LAYOUT_ergodox(
      _______,   KC_1,      KC_2,       KC_3,     KC_4,   KC_5,     _______,
      KC_BSLS,   KC_Q,      KC_W,       KC_E,     KC_R,   KC_T,     _______,
      KC_RBRC,   KC_A,      KC_S,       KC_D,     KC_F,   KC_G,
      KC_LSFT,   KC_Z,      KC_X,       KC_C,     KC_V,   KC_B,     _______,
      _______,   _______,   _______,    _______,  _______,
                                                                  _______,  _______,   _______,
                                                                  _______,  _______,   _______,





                                                            _______,  KC_6,     KC_7,     KC_8,       KC_9,     KC_0,    _______,
                                                            _______,  KC_Y,     KC_U,     KC_I,       KC_O,     KC_P,    KC_LBRACKET,
                                                                      KC_H,     KC_J,     KC_K,       KC_L,     KC_SCLN, KC_QUOTE,
                                                            _______,  KC_N,     KC_M,     KC_COMMA,   KC_DOT,   KC_SLASH,KC_RSFT,
                                                                                _______,  _______,    _______,  _______, _______,



                                              _______,      _______,   _______,
                                              _______,      _______,   _______
  ),

  [DG] = LAYOUT_ergodox(_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,LALT(LCTL(KC_T)),LALT(LCTL(KC_L)),_______,_______,_______,_______,_______,KC_7,KC_8,KC_9,_______,_______,_______,KC_4,KC_5,KC_6,KC_0,RESET,_______,_______,KC_1,KC_2,KC_3,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),

  [AR] = LAYOUT_ergodox(_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_UP,_______,_______,_______,_______,KC_LEFT,KC_DOWN,KC_RIGHT,_______,_______,_______,_______,LALT(LCTL(KC_DOWN)),KC_DOWN,LALT(LCTL(KC_UP)),_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______),

  [FU] = LAYOUT_ergodox(_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,KC_F10,KC_F11,KC_F12,_______,_______,_______,_______,KC_F7,KC_F8,KC_F9,_______,_______,_______,KC_F4,KC_F5,KC_F6,_______,_______,_______,_______,KC_F1,KC_F2,KC_F3,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case COLN_SCLN:
        override_key(KC_COLN, KC_SCLN);
        return false;
      case DQUO_QUOT:
        override_key(KC_DQUO, KC_QUOT);
        return false;
      case UKR_QWERT:
        switch_layout();
        return false;
    }
  }
  return true;
};
