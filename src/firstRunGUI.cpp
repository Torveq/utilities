#include <fxcg/display.h>
#include <fxcg/file.h>
#include <fxcg/keyboard.h>
#include <fxcg/system.h>
#include <fxcg/misc.h>
#include <fxcg/app.h>
#include <fxcg/serial.h>
#include <fxcg/rtc.h>
#include <fxcg/heap.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "powerGUI.hpp"
#include "menuGUI.hpp"
#include "selectorGUI.hpp"
#include "textGUI.hpp"
#include "graphicsProvider.hpp"
#include "hardwareProvider.hpp"
#include "keyboardProvider.hpp"
#include "timeProvider.hpp"
#include "firstRunGUI.hpp"
#include "settingsProvider.hpp"

void firstRunWizard() {
  Bdisp_AllClr_VRAM();
  int textX=0, textY=0;

  drawtnyimLogo( LCD_WIDTH_PX/2-138/2, LCD_HEIGHT_PX/2-42/2, 0);
  PrintMini(&textX, &textY, (unsigned char*)"brought to you by", 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 0, 0); //get length
  int textLen = textX;
  textY = LCD_HEIGHT_PX/2-42/2-24 - 20;
  textX = LCD_WIDTH_PX/2 - textLen/2;
  
  PrintMini(&textX, &textY, (unsigned char*)"brought to you by", 0, 0xFFFFFFFF, 0, 0, COLOR_GRAY, COLOR_WHITE, 1, 0);
  
  textX=0;
  PrintMini(&textX, &textY, (unsigned char*)"tny. internet media", 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 0, 0); //get length
  textLen = textX;
  textY = LCD_HEIGHT_PX/2+42/2-24;
  textX = LCD_WIDTH_PX/2 - textLen/2;
  int orange = drawRGB24toRGB565(210, 68, 19);
  PrintMini(&textX, &textY, (unsigned char*)"tny. ", 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  PrintMini(&textX, &textY, (unsigned char*)"i", 0, 0xFFFFFFFF, 0, 0, orange, COLOR_WHITE, 1, 0);
  PrintMini(&textX, &textY, (unsigned char*)"nternet ", 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  PrintMini(&textX, &textY, (unsigned char*)"m", 0, 0xFFFFFFFF, 0, 0, orange, COLOR_WHITE, 1, 0);
  PrintMini(&textX, &textY, (unsigned char*)"edia", 0, 0xFFFFFFFF, 0, 0, COLOR_BLACK, COLOR_WHITE, 1, 0);
  Bdisp_PutDisp_DD();
  blockForMilliseconds(3500);
  
  textArea text;
  strcpy(text.title, (char*)"Welcome to Utilities");
  
  textElement elem[20];
  text.elements = elem;
  text.allowEXE = 1;
  text.allowMkey = 0;
  
  elem[0].text = (char*)"This add-in provides functionality not originally present on Casio Prizm (fx-CG 10/20) calculators:";
  elem[1].newLine = 1;
  elem[1].lineSpacing = 5;
  elem[1].text = (char*)"- Clock and chronometer";
  elem[2].newLine = 1;
  elem[2].text = (char*)"- Calendar with agenda and tasklist";
  elem[3].newLine = 1;
  elem[3].text = (char*)"- Fine timeout&backlight adjustment";
  elem[4].newLine = 1;
  elem[4].text = (char*)"- File manager";
  elem[5].newLine = 1;
  elem[5].text = (char*)"- CPU clock adjustment";
  elem[6].newLine = 1;
  elem[6].text = (char*)"...and more";
  
  elem[7].newLine = 1;
  elem[7].lineSpacing = 8;
  elem[7].color = COLOR_ORANGE;
  elem[7].text = (char*)"Important notes:";
  
  elem[8].newLine = 1;
  elem[8].text = (char*)"To set time and date, as well as other settings, press Shift+Menu (Setup) at almost any point in the add-in.";
  
  elem[9].newLine = 1;
  elem[9].lineSpacing = 5;
  elem[9].text = (char*)"The CPU clock adjustment tool is hidden by default. To enable it, turn on the \"Show advanced tools\" setting.";
  
  elem[10].newLine = 1;
  elem[10].lineSpacing = 5;
  elem[10].text = (char*)"There is a calculator lock function, that allows for locking your calculator with a password.";
  
  elem[11].newLine = 1;
  elem[11].text = (char*)"Lock the calculator by pressing F5 on the home screen. You'll be prompted to set a password the first time you use this function.";
  elem[11].spaceAtEnd = 1;
  elem[12].text = (char*)"You can set a new password in the Settings menu.";
  
  elem[13].newLine = 1;
  elem[13].lineSpacing = 8;
  elem[13].text = (char*)"Thanks for reading these notes.";
  elem[14].newLine = 1;
  elem[14].text = (char*)"After pressing EXIT or EXE, you will probably be guided to adjust your calculator's clock.";
  
  elem[15].newLine = 1;
  elem[15].lineSpacing = 3;
  elem[15].text = (char*)"In case you need help with this software, contact info is on the \"About\" screen, to which you can get from the Settings menu.";
  
  text.numelements = 16;
  doTextArea(&text);
  SetSetting(SETTING_IS_FIRST_RUN, 0, 1);
}
 
