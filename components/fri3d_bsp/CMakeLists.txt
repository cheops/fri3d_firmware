set(SRCS
        "src/bsp_led.c"
        # "src/i2cdev.c"
        "src/led_blink_defaults.c"
)

if(CONFIG_FRI3D_BADGE_FOX)
        # list(APPEND SRCS "src/boards/fox/bsp_button.c")

elseif(CONFIG_FRI3D_BADGE_OCTOPUS)
        list(APPEND SRCS "src/boards/octopus/lis2hh12.c")

endif()

set(DEPS
        "driver"
)

set(PRIV_DEPS
        ""
)

idf_component_register(
        SRCS
        "${SRCS}"
        INCLUDE_DIRS
        "include"
        REQUIRES
        "${DEPS}"
        PRIV_REQUIRES
        "${PRIV_DEPS}"
)
