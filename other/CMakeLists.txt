add_subdirectory(poj)

add_executable(kmp kmp.c)
add_executable(dijkastra dijkastra.c)
add_executable(floyd floyd.c)
add_executable(buffer buffer.c)

add_executable(shell_sort sort/shell_sort.c)
add_executable(bubble_sort sort/bubble_sort.c)
add_executable(qsort sort/qsort.c)
add_executable(select_sort sort/select_sort.c)
add_executable(heap_sort sort/heap_sort.c)
add_executable(merge_sort sort/merge_sort.c)

add_executable(teststr test.c)
add_executable(testkk testkk.cpp)
