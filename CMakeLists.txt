
tdaq_package(NO_HEADERS)

tdaq_add_header_directory(oks/ DESTINATION oks)

tdaq_add_library(roks 
                 src/rlib/*.cpp 
                 LINK_LIBRARIES oks CORAL::CoralKernel CORAL::CoralBase CORAL::RelationalAccess Boost::date_time
                 DEFINITIONS TDAQ_CMT_RELEASE=\"${TDAQ_PROJECT_NAME}\")

tdaq_add_library(oks_utils src/lib/*.cpp LINK_LIBRARIES Boost::date_time AccessManager oks DEFINITIONS BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS)

tdaq_add_executable(oks_report_equal_objects   src/bin/oks_report_equal_objects.cpp   LINK_LIBRARIES oks Boost::program_options)
tdaq_add_executable(oks_get_schema             src/bin/oks_get_schema.cpp             LINK_LIBRARIES roks)
tdaq_add_executable(oks_get_data               src/bin/oks_get_data.cpp               LINK_LIBRARIES roks)
tdaq_add_executable(oks_ls_data                src/bin/oks_ls_data.cpp                LINK_LIBRARIES oks_utils roks)
tdaq_add_executable(oks_report_no_descriptions src/bin/oks_report_no_descriptions.cpp LINK_LIBRARIES oks)
tdaq_add_executable(oks_merge                  src/bin/oks_merge.cpp                  LINK_LIBRARIES oks)
tdaq_add_executable(oks_refresh                src/bin/oks_refresh.cpp                LINK_LIBRARIES oks Boost::program_options)
tdaq_add_executable(oks_diff_data              src/bin/oks_diff_data.cpp              LINK_LIBRARIES oks)
tdaq_add_executable(oks_diff_schema            src/bin/oks_diff_schema.cpp            LINK_LIBRARIES oks)
tdaq_add_executable(oks_tutorial               src/bin/oks_tutorial.cpp               LINK_LIBRARIES oks)

tdaq_add_executable(oks_utils_alloc_test       examples/alloc.cpp                     LINK_LIBRARIES Boost::system NOINSTALL)

tdaq_add_library(xmoks src/xm-lib/*.cpp INCLUDE_DIRECTORIES src LINK_LIBRARIES X11 osw oks xmext)

tdaq_add_executable(oks_data_editor 
                    src/xm-gui/data_editor*.cpp
                    src/xm-gui/g_class.cpp
                    src/xm-gui/g_context.cpp
                    src/xm-gui/g_dnd.cpp
                    src/xm-gui/g_ref_tree.cpp
                    src/xm-gui/g_window*.cpp
                    src/xm-gui/g_object*.cpp
                    INCLUDE_DIRECTORIES 
                        src
                    LINK_LIBRARIES 
                        oks_utils xmoks oks xmext stdc++fs X11
                    DEFINITIONS 
                        TDAQ_CMT_RELEASE=\"${TDAQ_PROJECT_NAME}\"
                        OKS_DATA_EDITOR_ONLINE_HELP_DIR="share/data"
                    )

tdaq_add_executable(oks_schema_editor src/xm-gui/schema_editor*.cpp INCLUDE_DIRECTORIES src LINK_LIBRARIES xmoks oks xmext X11)

# tests and examples left as an exercise for now...

tdaq_add_data(data/online-help/data-editor/*.html data/online-help/data-editor/*.gif DESTINATION ../oks/online-help/data-editor)
tdaq_add_data(src/xm-gui/*.xml src/xm-lib/*.xml DESTINATION ../oks/gui)
tdaq_add_data(data/xsl/*.xsl DESTINATION ../oks/xsl)

tdaq_add_scripts(scripts/*)

tdaq_add_data(src/rlib/date_time_zonespec.csv DESTINATION ../Boost)

add_test(NAME oks_check COMMAND ${TDAQ_RUNNER} ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.sh ${CMAKE_CURRENT_BINARY_DIR})

configure_file(post_install.sh.in post_install.sh @ONLY)
