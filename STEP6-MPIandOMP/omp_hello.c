#include <omp.h>
#include <stdio.h>

int main()
{
// start paral;el
#pragma omp parallel
    {
        // thread id
        int id = omp_get_thread_num();
        printf("Hello from thread %d\n", id);
    }
    return 0;
}