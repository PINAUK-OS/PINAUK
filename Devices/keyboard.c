#include "scancodes.c"

void kb_getinput() 
{
	// Stub for now (no kb drivers yet)
}
uint8_t keycode_to_ascii(uint8_t keycode, bool shift, bool capslock) 
{
	// Letters
	if (keycode >= keycode_a && keycode <= keycode_z) 
	{
		char base = capslock ? 'A' : 'a';
		return base + (keycode - keycode_a);
	}
    // Number row
    if (!shift) 
    {
        switch (keycode) 
        {
            case keycode_grave:   return '`';
            case keycode_1:       return '1';
            case keycode_2:       return '2';
            case keycode_3:       return '3';
            case keycode_4:       return '4';
            case keycode_5:       return '5';
            case keycode_6:       return '6';
            case keycode_7:       return '7';
            case keycode_8:       return '8';
            case keycode_9:       return '9';
            case keycode_0:       return '0';
            case keycode_minus:   return '-';
            case keycode_equals:  return '=';
        }
    }
    else 
    {
        switch (keycode) 
        {
            case keycode_grave:   return '~';
            case keycode_1:       return '!';
            case keycode_2:       return '@';
            case keycode_3:       return '#';
            case keycode_4:       return '$';
            case keycode_5:       return '%';
            case keycode_6:       return '^';
            case keycode_7:       return '&';
            case keycode_8:       return '*';
            case keycode_9:       return '(';
            case keycode_0:       return ')';
            case keycode_minus:   return '_';
            case keycode_equals:  return '+';
        }
    }

    // Other symbols
    if (!shift) 
    {
        switch (keycode) 
        {
            case keycode_tab:      return '\t';
            case keycode_space:    return ' ';
            case keycode_opsqbr:   return '[';
            case keycode_clsqbr:   return ']';
            case keycode_bckslsh:  return '\\';
            case keycode_semicln:  return ';';
            case keycode_apstrph:  return '\'';
            case keycode_comma:    return ',';
            case keycode_period:   return '.';
            case keycode_slash:    return '/';
        }
    }
    else 
    {
        switch (keycode) 
        {
            case keycode_opsqbr:   return '{';
            case keycode_clsqbr:   return '}';
            case keycode_bckslsh:  return '|';
            case keycode_semicln:  return ':';
            case keycode_apstrph:  return '"';
            case keycode_comma:    return '<';
            case keycode_period:   return '>';
            case keycode_slash:    return '?';
        }
    }

    // Numpad digits
    if (keycode >= keycode_numpad0 && keycode <= keycode_numpad9) 
    {
        return '0' + (keycode - keycode_numpad0);
    }

    // Numpad symbols
    switch (keycode) 
    {
        case keycode_numpad_period:    return '.';
        case keycode_numpad_slash:     return '/';
        case keycode_numpad_asterisk:  return '*';
        case keycode_numpad_minus:     return '-';
        case keycode_numpad_plus:      return '+';
    }

    return 0; // No ASCII equivalent (but what the fuck is your key then? e-mail me)
}