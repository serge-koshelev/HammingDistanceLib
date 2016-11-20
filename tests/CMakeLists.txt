#########################################################################
# Copyright (C) 2016 Sergey Koshelev                                    #
#########################################################################

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories (${Boost_INCLUDE_DIRS})

  
#I like to keep test files in a separate source directory called test
file(GLOB TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)

#Run through each source
foreach(testSrc ${TEST_SRCS})
  # Extract the filename without an extension
  get_filename_component(testName ${testSrc} NAME_WE)

  # Add the compile target
  add_executable(${testName} ${testSrc})

  # Link to Boost libraries and targets and dependencies
  target_link_libraries(${testName} ${Boost_LIBRARIES} HammingDistance)

  #I like to move testing binaries into a testBin directory
  set_target_properties(${testName} PROPERTIES 
                        RUNTIME_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR}/testBin)

  #add it to test execution
  add_test(NAME ${testName} 
           WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/testBin 
           COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/testBin/${testName} )
endforeach(testSrc)
