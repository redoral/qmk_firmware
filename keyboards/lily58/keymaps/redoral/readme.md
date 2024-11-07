# redoral's custom via-compatible keymap for Lily58

Based on the `via` keymap and modified it to my own keymap and OLED display preference.

## Features

-   Qwerty base, custom MO(1) layer tailored to my own preference
-   All transparent MO(2) and MO(3) layers (as a base)
-   The OLED on the left half shows my name, layer status, and last pressed key by row x col
-   The OLED on the other half displays a bongo cat animation, courtesy of https://github.com/Rwarcards762/lily58_bongocat
-   Mouse keys support, MO(1) layer by default has mouse key bindings on offhand board
-   VIA support
-   RP2040 pro micro conversion in `rules.mk` so no need to use `-e CONVERT_TO=promicro_rp2040` flag when flashing
