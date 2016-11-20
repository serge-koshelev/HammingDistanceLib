#########################################################################
# Copyright (C) 2016 Sergey Koshelev                                    #
#########################################################################

# Treat all .h files as include files
FILE(GLOB all_headers *.h)
source_group(include FILES ${all_headers})

# Treat all .cpp files as source files
FILE(GLOB all_srcs *.cpp)
source_group(source FILES ${all_srcs})

add_executable(calchd
   ${all_srcs}
   ${all_headers}
)
target_link_libraries(calchd HammingDistance)
   
install(TARGETS calchd
   DESTINATION bin
)
