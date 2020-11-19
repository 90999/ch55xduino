

#define LED_BUILTIN 33

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(15, OUTPUT);
}
__xdata uint8_t ledData[8];
void neopixel_show_long(uint32_t dataAndLen) {
  //’dpl’ (LSB),’dph’,’b’ & ’acc’
  //DPTR is the array address, B is the low byte of length, A is the high byte of length

  __asm__ ("    mov r3, b                           \n"
           //"    mov r4, a                           \n"




           ";save EA to R6                          \n"
           "    mov c,_EA                           \n"
           "    clr a                               \n"
           "    rlc a                               \n"
           "    mov r6, a                           \n"
           ";disable interrupt                      \n"
           "    clr _EA                             \n"

           ";decrease R3 by 1                    \n"
           "    dec r3                              \n"
           "    cjne r3,#0xFF,startNewByte$  \n"
           ";quit is R3 is already 0xFF        \n"
           "    ljmp neopixelSendFinish$            \n"
           //even odd?



           //even may skip a byte, may leaving it 0xFF, and the MOV R7,A may affect R7
           //CH552 can save 1 instruction of jump/branch insctruction go to an even addr
           ".even \n"
           "startNewByte$:                   \n"
           "    movx  a,@dptr                          \n"  //todo merge it to reduce time consumption
           "    inc dptr                          \n"


           //bit7
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit7skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit7skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit7skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit7skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit6
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit6skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit6skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit6skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit6skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit5
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit5skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit5skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit5skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit5skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit4
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit4skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit4skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit4skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit4skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit3
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit3skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit3skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit3skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit3skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit2
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit2skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit2skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit2skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit2skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit1
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit1skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit1skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit1skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit1skipHighNop$:                \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"

           //bit0
           "    setb _P1_5                   \n"
           "    rlc a                        \n"
           "    nop                          \n"  //make it even
           "    jnc bit0skipLowNop$           \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit0skipLowNop$:                 \n"
           "    clr _P1_5                    \n"
           "    jc bit0skipHighNop$         \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "bit0skipHighNop$:                \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"
           //"    nop                          \n"

           "    dec r3                       \n"
           "    cjne r3,#0xFF,decLen16bit$   \n"
           "    nop                          \n"
           "    nop                          \n"
           "    nop                          \n"
           "    setb _P1_5                   \n"
           "    ljmp neopixelSendFinish$     \n"
           "decLen16bit$:                    \n"
           "    ljmp startNewByte$           \n"
           "neopixelSendFinish$:                    \n"

           ";restore EA from R6                     \n"
           "    mov a,r6                            \n"
           "    jz  skipRestoreEA_NP$               \n"
           "    setb  _EA                           \n"
           "skipRestoreEA_NP$:                      \n"
          );





  //movx  a,@dptr
  //B = ledData[0];


}

// the loop function runs over and over again forever
void loop() {
  ledData[0] = 0x00;  //G
  ledData[1] = 0x0F;  //R
  ledData[2] = 0x0F;  //B

  neopixel_show_long((((uint16_t)ledData) & 0xFFFF) | (((uint32_t)3 & 0xFF) << 16));
  delay(10);
}
