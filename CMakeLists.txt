cmake_minimum_required(VERSION 3.12)
project(oks_utils VERSION 0.0.0)

find_package(daq-cmake REQUIRED)

daq_setup_environment()

find_package(oks)
find_package(Boost COMPONENTS date_time program_options system REQUIRED)
find_package(ers REQUIRED)
find_package(logging REQUIRED)

daq_add_library(lib/*.cpp LINK_LIBRARIES Boost::date_time oks )
#tdaq_add_library(oks_utils src/lib/*.cpp LINK_LIBRARIES Boost::date_time AccessManager oks DEFINITIONS BOOST_NO_CXX11_EXPLICIT_CONVERSION_OPERATORS)

daq_add_application(oks_report_equal_objects   oks_report_equal_objects.cxx   LINK_LIBRARIES oks Boost::program_options)
daq_add_application(oks_report_no_descriptions oks_report_no_descriptions.cxx LINK_LIBRARIES oks)
daq_add_application(oks_merge                  oks_merge.cxx                  LINK_LIBRARIES oks)
daq_add_application(oks_refresh                oks_refresh.cxx                LINK_LIBRARIES oks Boost::program_options)
daq_add_application(oks_diff_data              oks_diff_data.cxx              LINK_LIBRARIES oks)
daq_add_application(oks_diff_schema            oks_diff_schema.cxx            LINK_LIBRARIES oks)
daq_add_application(oks_tutorial               oks_tutorial.cxx               LINK_LIBRARIES oks)

daq_add_application(oks_utils_alloc_test       alloc.cxx               TEST      LINK_LIBRARIES Boost::system )

# JCF: seems potentially worthwhile to build some of the other executables which are currently ignored in test/apps...

daq_install()
