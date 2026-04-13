set(lab02_SOURCE lab02.cxx)
GENERATECLP(lab02_SOURCE lab02.xml)

add_executable(lab02_${MYHAWKID} ${lab02_SOURCE})
target_link_libraries(lab02_${MYHAWKID} ${ITK_LIBRARIES})