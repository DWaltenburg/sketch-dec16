#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_F_4W_HW_SPI   u8g2  (U8G2_R0, 5, 22, 17);

void setup() {
  // put your setup code here, to run once:
  u8g2.begin();
  u8g2.setPowerSave(0);
  u8g2.setFlipMode(0);
}

void drawLogo(void)
{
  uint8_t mdy = 0;
  if ( u8g2.getDisplayHeight() < 59 )
    mdy = 5;


  u8g2.setFontMode(1);  // Transparent
  u8g2.setDrawColor(1);
#ifdef MINI_LOGO

  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_inb16_mf);
  u8g2.drawStr(0, 22, "U");

  u8g2.setFontDirection(1);
  u8g2.setFont(u8g2_font_inb19_mn);
  u8g2.drawStr(14, 8, "8");

  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_inb16_mf);
  u8g2.drawStr(36, 22, "g");
  u8g2.drawStr(48, 22, "\xb2");

  u8g2.drawHLine(2, 25, 34);
  u8g2.drawHLine(3, 26, 34);
  u8g2.drawVLine(32, 22, 12);
  u8g2.drawVLine(33, 23, 12);
#else

  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_inb24_mf);
  u8g2.drawStr(0, 30 - mdy, "U");

  u8g2.setFontDirection(1);
  u8g2.setFont(u8g2_font_inb30_mn);
  u8g2.drawStr(21, 8 - mdy, "8");

  u8g2.setFontDirection(0);
  u8g2.setFont(u8g2_font_inb24_mf);
  u8g2.drawStr(51, 30 - mdy, "g");
  u8g2.drawStr(67, 30 - mdy, "\xb2");

  u8g2.drawHLine(2, 35 - mdy, 47);
  u8g2.drawHLine(3, 36 - mdy, 47);
  u8g2.drawVLine(45, 32 - mdy, 12);
  u8g2.drawVLine(46, 33 - mdy, 12);

#endif

}

void drawURL(void)
{
#ifndef MINI_LOGO
  u8g2.setFont(u8g2_font_4x6_tr);
  if ( u8g2.getDisplayHeight() < 59 )
  {
    u8g2.drawStr(89, 20 - 5, "github.com");
    u8g2.drawStr(73, 29 - 5, "/olikraus/u8g2");
  }
  else
  {
    u8g2.drawStr(1, 54, "github.com/olikraus/u8g2");
  }
#endif
}

void loop() {
  // put your main code here, to run repeatedly:
  u8g2.firstPage();
  do {
    drawLogo();
    drawURL();
  } while ( u8g2.nextPage() );
  delay(4000);
}
