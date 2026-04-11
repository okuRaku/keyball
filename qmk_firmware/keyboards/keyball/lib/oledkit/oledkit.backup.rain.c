/*
Copyright 2021 @Yowkees
Copyright 2021 MURAOKA Taro (aka KoRoN, @kaoriya)

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
                     
#include "quantum.h"

#if defined(OLED_ENABLE) && !defined(OLEDKIT_DISABLE)

// uint8_t    anim_frame       = 0;  // global animation counter.
uint32_t   starry_night_anim_timer = 0;
// uint8_t    last_byte              = 0b00000001;

/*
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000001;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000000;
uint8_t    last_byte              = 0b00000001;
*/

#define NUM_BITS 8 // Assuming 8 bits in a byte
#define ANIMATION_LENGTH 16 // Length of the animation sequence

uint8_t anim_frame_saver1[NUM_BITS]; // Array to store animation frame index for each bit position
uint8_t anim_frame_saver2[NUM_BITS]; // Array to store animation frame index for each bit position
uint8_t anim_frame_saver3[NUM_BITS]; // Array to store animation frame index for each bit position
uint8_t anim_frame_saver4[NUM_BITS]; // Array to store animation frame index for each bit position
// uint8_t bit_off_counter[NUM_BITS]; // Array to store counter for how long a bit stays off

// Define animation sequence
// const uint8_t animation_sequence[] =    {0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1};
// const uint8_t animation_sequence[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0};
const uint8_t animation_sequence[] = {

    // 0b10100110,
    // 0b00101100,
    // 0b10011000,
    // 0b10110000,
    // 0b01100000,
    // 0b11000000,
    // 0b10000000,
    // 0b00000000,
    // 0b00000000,
    // 0b00000001,
    // 0b00000010,
    // 0b00000101,
    // 0b00001001,
    // 0b00010100,
    // 0b00100101,
    // 0b01010011,
    0b11111111,   //0b01010011,
    1,   //0b00100101,
    2,   //0b00010100,
    3,   //0b00001001,
    4,   //0b00000101,
    5,   //0b00000010,
    6,   //0b00000001,
    7,   //0b00000000,
    8,   //0b00000000,
    9,   //0b10000000,
    10,   //0b11000000,
    11,   //0b01100000,
    12,   //0b10110000,
    13,   //0b10011000,
    14,   //0b00101100,
    15,   //0b10100110,
    };
// const int animation_sequence_length = sizeof(animation_sequence);

// Function to initialize bit animation frame array randomly
void initialize_anim_frame_saver(void) {
    for (int i = 0; i < NUM_BITS; i++) {
        anim_frame_saver1[i] = rand() % ANIMATION_LENGTH; // Initialize each bit's animation frame randomly
        anim_frame_saver2[i] = rand() % ANIMATION_LENGTH; // Initialize each bit's animation frame randomly
        anim_frame_saver3[i] = rand() % ANIMATION_LENGTH; // Initialize each bit's animation frame randomly
        anim_frame_saver4[i] = rand() % ANIMATION_LENGTH; // Initialize each bit's animation frame randomly
        // bit_off_counter[i] = 0; // Initialize off counter to 0
    }
}

// Function to update bit animation frame array based on timer iteration
void update_anim_frame_saver(uint8_t *saver, uint32_t randomizer) {
    for (int i = 0; i < NUM_BITS; i++) {
        if ((saver[i] == 0) && 0 ) { //(((randomizer >> i) % 10) > 2)) {
            // do nothing
        } else {
            // If the bit is on, increment the animation frame
            switch((randomizer >> i) & 3) {
                case 0: 
                    if(saver[i] > 12){
                        saver[i] = saver[i] - 13;
                    } else{
                        saver[i] = saver[i] + 3;  
                    }
                    break;
                case 1: 
                    if(saver[i] == 15){
                        saver[i] = 0;
                    } else{
                        saver[i] = saver[i] + 1;  
                    }
                    break;
                case 2: 
                    if(saver[i] > 13){
                        saver[i] = saver[i] - 12;
                    } else{
                        saver[i] = saver[i] + 2;  
                    }
                    break;
                case 3: 
                    if(saver[i] == 15){
                        saver[i] = 0;
                    } else{
                        saver[i] = saver[i] + 1;  
                    }
                    break;
                default: 
                    if(saver[i] == 15){
                        saver[i] = 0;
                    } else{
                        saver[i] = saver[i] + 1;  
                    }
                    break;   

            }
            // if(anim_frame_saver[i] == 15){//== ANIMATION_LENGTH) {
            //     anim_frame_saver[i] = 0;
            // } else{
            //     anim_frame_saver[i] = anim_frame_saver[i] + 1;  
            // }
        }
    }
}

uint8_t offsetAnim(uint8_t animation_index, uint8_t offset) {
    return (animation_index + offset) % ANIMATION_LENGTH;
}

// Function to apply animation sequence to a specific bit position in a byte
// __attribute__((weak)) uint8_t applyAnim(uint8_t byte, int bit_position) {
//     int sequence_index = anim_frame_saver[bit_position] % animation_sequence_length; // Determine animation frame index for the bit position
//     if (animation_sequence[sequence_index] == 0) {
//         return byte &= ~(1 << bit_position); // Clear the bit at the specified position to 0
//     } else {
//         return byte |= (1 << bit_position);  // Set the bit at the specified position to 1
//     }
// }

// uint8_t rotateAnim(uint8_t byte, int amount) {
//     for(int i = 0; i<amount; i++){
//         byte = (byte >> 1) | (byte << 7);
//     }
//     return byte;
// }

uint8_t offsetCol(uint8_t column) {
    return column+32;
}

uint8_t applyAnimation(uint8_t *saver, uint8_t byteRow, uint8_t offset, uint8_t translate) {
    // special handling when at the "top" of the rain fall
    // if((offset+1) % 128 == 0) {
    //     return 0xFF; //(randomizer >> i) & 3
    // }
    // uint8_t returnByte;
    for(int i = 0; i<8; i++){
        // get i'th bit of the proper animation frame
        uint8_t bitToSet = (animation_sequence[offsetAnim(saver[i], offset+translate)] >> i) & 1;

        // clear i'th bit and set it to above animation frame bit
        byteRow = (byteRow & ~(1 << i)) | (bitToSet << i);
    }
    return byteRow;
}

__attribute__((weak)) void oledkit_render_logo_user(void) {
    uint32_t elapsed = timer_elapsed32(starry_night_anim_timer);
    if (elapsed > 175) {
        
        starry_night_anim_timer = timer_read32();
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],0);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],32);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],64);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],96);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],128);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],160);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],192);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],224);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],256);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],288);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],16);
        // oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 8)],48);

        // draw full column offset goes from 0 to 128
        for(int i = 0; i < 16; i++){
            for(int j = 0; j < 8; j++){

                // if((i/16 % 2)){
                //   //oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],i*8+j);
                //   oled_write_raw_byte(applyAnimation(0, i*8+j), i*8+j);
                // } else {
                 // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],i*8+j);
                    oled_write_raw_byte(applyAnimation(anim_frame_saver1, 0, i*8+j, 0), i*8+j);
                // }
            }
        }
        // for(int i = 16; i < 32; i++){
        //     for(int j = 0; j < 8; j++){

        //         // if((i/16 % 2)){
        //         //   //oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],i*8+j);
        //         //   oled_write_raw_byte(applyAnimation(0, i*8+j), i*8+j);
        //         // } else {
        //          // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],i*8+j);
        //             oled_write_raw_byte(applyAnimation(anim_frame_saver3, 0, i*8+j, 7), i*8+j);
        //         // }
        //     }
        // }
        // for(int i = 32; i < 48; i++){
        //     for(int j = 0; j < 8; j++){

        //         // if((i/16 % 2)){
        //         //   //oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],i*8+j);
        //         //   oled_write_raw_byte(applyAnimation(0, i*8+j), i*8+j);
        //         // } else {
        //          // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],i*8+j);
        //             oled_write_raw_byte(applyAnimation(anim_frame_saver4, 0, i*8+j, 2), i*8+j);
        //         // }
        //     }
        // }
        for(int i = 48; i < 64; i++){
            for(int j = 0; j < 8; j++){

                // if((i/16 % 2)){
                //   //oled_write_raw_byte(animation_sequence[offsetAnim(anim_frame_saver[0], 7)],i*8+j);
                //   oled_write_raw_byte(applyAnimation(0, i*8+j), i*8+j);
                // } else {
                 // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],i*8+j);
                    oled_write_raw_byte(applyAnimation(anim_frame_saver2, 0, i*8+j, 4), i*8+j);
                // }
            }
        }

        // 16 per column 
        // for(int i = 0; i < 64; i++){
        //     oled_write_raw_byte(0xFF,i*8);
        //     oled_write_raw_byte(0xAA,i*8+1);
        //     oled_write_raw_byte(0xFF,i*8+2);
        //     oled_write_raw_byte(0xAA,i*8+3);
        //     oled_write_raw_byte(0xFF,i*8+4);
        //     oled_write_raw_byte(0xAA,i*8+5);
        //     oled_write_raw_byte(0xFF,i*8+6);
        //     oled_write_raw_byte(0xAA,i*8+7);
        //     // oled_write_raw_byte(0xAA,offsetCol(i*64));
        // }

        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],48);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[10]],37);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],64);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],80);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[3]],69);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],96);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],112);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[10]],101);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],128);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],144);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[3]],133);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],160);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],176);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[10]],165);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],192);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],208);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[3]],197);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],224);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],240);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[10]],229);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],256);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[0]],272);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[3]],261);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],288);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[7]],304);
        // oled_write_raw_byte(animation_sequence[anim_frame_saver[10]],293);

        update_anim_frame_saver(anim_frame_saver1, elapsed); // Update animation frame for each bit
        update_anim_frame_saver(anim_frame_saver2, elapsed); // Update animation frame for each bit
        update_anim_frame_saver(anim_frame_saver3, elapsed); // Update animation frame for each bit
        update_anim_frame_saver(anim_frame_saver4, elapsed); // Update animation frame for each bit
        
        // for (int i = 0; i < 512; i++) {
        //     // Get the byte to update
        //     uint8_t byte_to_update = last_byte;
            
        //     // Apply animation to each bit position in the byte
        //     for (int bit_position = 0; bit_position < NUM_BITS; bit_position++) {
        //         byte_to_update = applyAnim(byte_to_update, bit_position);
        //     }
            
        //     // Write the updated byte to the OLED display
        //     oled_write_raw_byte(byte_to_update, i);
        // }
    }
}

// __attribute__((weak)) void oledkit_render_logo_user(void) {
//     if (timer_elapsed32(starry_night_anim_timer) > 100) {
//         starry_night_anim_timer = timer_read32();
//         // oled_write_pixel(0, timer_read32() % 128, true);
//         if(anim_frame > 16){
//             anim_frame = 0;
//         } else {
//             anim_frame+=1;
//         }
//         for (int i = 0; i<512; i++){
//             oled_write_raw_byte(last_byte, i);
        
//         }
//         last_byte = (last_byte >> 1) | (last_byte << 7);
//         // last_byte = rand() % 255;
//     }
//     // for (int i = 0; i<9; i++){
//     //     for (int j = 120; j<128; j++){
//     //         oled_write_pixel(i, j, true);
//     //     }
//     // }


//     // Require `OLED_FONT_H "keyboards/keyball/lib/logofont/logofont.c"`
//     // char ch = 0x80;
//     // switch (get_highest_layer(layer_state)) {
//     //     case 2:
//     //         for (int y = 0; y < 3; y++) {
//     //             oled_write_P(PSTR("  "), true);
//     //             for (int x = 0; x < 16; x++) {
//     //                 oled_write_char(ch++, true);
//     //             }
//     //             oled_advance_page(false);
//     //         }
//     //         break;
//     //     default:
//     //         for (int y = 0; y < 3; y++) {
//     //             oled_write_P(PSTR("  "), false);
//     //             for (int x = 0; x < 16; x++) {
//     //                 oled_write_char(ch++, false);
//     //             }
//     //             oled_advance_page(false);
//     //         }
//     //         break;
//     // }
// }

__attribute__((weak)) void oledkit_render_info_user(void) {
    oledkit_render_logo_user();
}

__attribute__((weak)) bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oledkit_render_info_user();
    } else {
        oledkit_render_logo_user();
    }
    return true;
}

__attribute__((weak)) oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    // Logo needs to be rotated 180 degrees.
    //
    // A typical OLED has a narrow margin on the left side near the origin, and
    // a wide margin on the right side. The Keyball logo consists of three
    // lines. If the logo is displayed on an OLED consisting of four lines, the
    // margin on the right side will be too large and the balance is not good.
    //
    // Additionally, by rotating it, the left side of the logo will be above
    // the OLED screen, giving it a natural look.
    // return !is_keyboard_master() ? OLED_ROTATION_180 : rotation;
    initialize_anim_frame_saver();
    return !is_keyboard_master() ? rotation : rotation;
}

#endif // OLED_ENABLE
