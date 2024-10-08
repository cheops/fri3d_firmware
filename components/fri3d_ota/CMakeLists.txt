include(${CMAKE_BINARY_DIR}/../../../cmake/fri3d_component.cmake)

set(SRCS
        "src/firmware.cpp"
        "src/firmware_fetcher.cpp"
        "src/flasher.cpp"
        "src/ota.cpp"
        "src/semver.c"
        "src/version.cpp"
)

set(DEPS
        "fri3d_application"
)

set(PRIV_DEPS
        "esp_https_ota"
        "mbedtls"
        "esp-tls"
        "app_update"
        "json"
)

idf_component_register(
        SRCS
        "${SRCS}"
        INCLUDE_DIRS
        "include"
        PRIV_INCLUDE_DIRS
        "src/include"
        REQUIRES
        "${DEPS}"
        PRIV_REQUIRES
        "${PRIV_DEPS}"
)

fri3d_set_loglevel()
