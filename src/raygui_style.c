#include "raygui.h"

// Copyright (c) 2020-2025 raylib technologies (@raylibtech)                    //

#define TERMINAL_STYLE_PROPS_COUNT  17

// Custom style name: Terminal
static const GuiStyleProp terminalStyleProps[TERMINAL_STYLE_PROPS_COUNT] = {
    { 0, 0, (int)0x1c8d00ff },    // DEFAULT_BORDER_COLOR_NORMAL 
    { 0, 1, (int)0x161313ff },    // DEFAULT_BASE_COLOR_NORMAL 
    { 0, 2, (int)0x38f620ff },    // DEFAULT_TEXT_COLOR_NORMAL 
    { 0, 3, (int)0xc3fbc6ff },    // DEFAULT_BORDER_COLOR_FOCUSED 
    { 0, 4, (int)0x43bf2eff },    // DEFAULT_BASE_COLOR_FOCUSED 
    { 0, 5, (int)0xdcfadcff },    // DEFAULT_TEXT_COLOR_FOCUSED 
    { 0, 6, (int)0x1f5b19ff },    // DEFAULT_BORDER_COLOR_PRESSED 
    { 0, 7, (int)0x43ff28ff },    // DEFAULT_BASE_COLOR_PRESSED 
    { 0, 8, (int)0x1e6f15ff },    // DEFAULT_TEXT_COLOR_PRESSED 
    { 0, 9, (int)0x223b22ff },    // DEFAULT_BORDER_COLOR_DISABLED 
    { 0, 10, (int)0x182c18ff },    // DEFAULT_BASE_COLOR_DISABLED 
    { 0, 11, (int)0x244125ff },    // DEFAULT_TEXT_COLOR_DISABLED 
    { 0, 16, (int)0x00000010 },    // DEFAULT_TEXT_SIZE 
    { 0, 17, (int)0x00000000 },    // DEFAULT_TEXT_SPACING 
    { 0, 18, (int)0xe6fce3ff },    // DEFAULT_LINE_COLOR 
    { 0, 19, (int)0x0c1505ff },    // DEFAULT_BACKGROUND_COLOR 
    { 0, 20, (int)0x00000018 },    // DEFAULT_TEXT_LINE_SPACING 
};

// Style loading function: Terminal
static void raygui_load_style(Font font) {
    // Load style properties provided
    // NOTE: Default properties are propagated
    for (int i = 0; i < TERMINAL_STYLE_PROPS_COUNT; i++)
    {
        GuiSetStyle(terminalStyleProps[i].controlId, terminalStyleProps[i].propertyId, terminalStyleProps[i].propertyValue);
    }

    GuiSetFont(font);

    // Setup a white rectangle on the font to be used on shapes drawing,
    // it makes possible to draw shapes and text (full UI) in a single draw call
    Rectangle fontWhiteRec = { 510, 254, 1, 1 };
    SetShapesTexture(font.texture, fontWhiteRec);

    //-----------------------------------------------------------------

    // TODO: Custom user style setup: Set specific properties here (if required)
    // i.e. Controls specific BORDER_WIDTH, TEXT_PADDING, TEXT_ALIGNMENT
}

