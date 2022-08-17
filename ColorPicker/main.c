/*
 *                           0BSD 
 * 
 *                    BSD Zero Clause License
 * 
 *  Copyright (c) 2021 Hermann Meyer
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted.

 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH
 * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,
 * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM
 * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
 * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 *
 */

#include "CairoColorPicker.h"

int main () {

#ifdef ENABLE_NLS
    // set Message type to locale to fetch localisation support
    setlocale (LC_MESSAGES, "");
    bindtextdomain(GETTEXT_PACKAGE, LOCAL_DIR);
    bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
    textdomain(GETTEXT_PACKAGE);
#endif

    // set Ctype to C to avoid symbol clashes from different locales
    setlocale (LC_CTYPE, "C");

    Xputty main;
    main_init(&main);

    Widget_t * w = create_color_chooser (&main);
    show_color_chooser(w);
    main_run(&main);
    XUngrabKey(main.dpy, XKeysymToKeycode(main.dpy,XK_Control_L),
                                    AnyModifier, DefaultRootWindow(main.dpy));
    XUngrabKey(main.dpy, XKeysymToKeycode(main.dpy,XK_Control_R),
                                    AnyModifier, DefaultRootWindow(main.dpy));
    main.key_snooper = NULL;
    main_quit(&main);
    return 0;
}
