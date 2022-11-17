#include <iostream>
#include <cmath>
#define start_size 100

template <typename T>

class heap{
    public:
        int size;
        T *array;

        heap(){
            size = 0;
            array = new T[start_size]
        };

        heap(arr){
            size = sizeof(arr);
            array = new T[size];
            for (i = 0; i < (sizeof(arr)/sizeof(T)); ++i){
                array[i] = arr[i];
            };
            check_down(0);
        };

        ~heap(){
            delete array [];
        };

        void insert(T val){
            h[++size]=x;
            Shift_up(size - 1);
        };

        void get_max(T *x){
            if(size == 0) return 0;
        	*x = h[1];
            h[1] = h[size--];
            checkdown(0);
        };


    private:
        void Shift_up(int c){
            int p;
            p = c / 2;
            if (p == 0) return;
            else if (array[c] > array[p]){
                T sub;
                sub = array[c];
                array[c] = array[p];
                array[c] = sub;
                Shift_up(p);
            };
        };
        void Shift_down(int c){
            int c;
            c = 2 * p;
            if (c > size ) return;
            if (c + 1 <= size && h[c + 1] > h[c]) c++;
            if (h[c] > h[p]) {
                T sub;
                sub =  h[c];
                h[c] = h[p];
                h[p] = sub;
                checkdown(c);
            };
        };
};
