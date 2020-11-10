int active_layer;

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_0);
#endif
};

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = biton32(state);
    active_layer = layer;
    switch (layer) {
      case DV:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case QW:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case DG:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case FU:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        active_layer = 0;
        break;
    }
    return state;
};
