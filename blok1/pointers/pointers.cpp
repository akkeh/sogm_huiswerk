#include <iostream>
#include <cmath>

void rectest(short arr[], int N, int depth) {
    std::cout << "depth: " << depth << " : " << arr[depth] << std::endl;
    if(depth < N-1) {
        rectest(arr, N, depth+1);    
    } 

}

int main() {
    const int length = 4;
    short arr[] = {19, 12, 33, 42};
/* equivalent:
    short *arr;
    arr = new short[length];
*/
    for(int i=0; i<length; i++) {
        std::cout << arr[i] << std::endl;
    }
    for(int i=0; i<length; i++) {
        std::cout << *(arr+i) << std::endl;     //  pointer-address wordt 
                                                //  veranderd
    }
    short* arr_ptr;
    arr_ptr = arr;                      //  pointer is een getal, 
                                        //  welke het adres van arr[0] is
    for(int i=0; i<length; i++) {
        std::cout << *arr_ptr << std::endl;
        arr_ptr++;                      // incrementeer pointer-adres
    }

    rectest(arr, length, 0);
    
    
    return 0;
}
