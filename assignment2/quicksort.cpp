    #include<iostream>
    #include<cstring>
    using namespace std;
    #define maxSize 5

    class quickSort{
        public:
        int x[maxSize] = {1,5,3,6,2};

        int partition(int y[maxSize], int l, int h);
        void quicksort(int e[maxSize], int l, int h);   
        void swap(int &e, int &f); 
        void print(int e[maxSize]);
    };

    void quickSort::print(int e[maxSize]){
        for(int i = 0; i<maxSize; i++){
            cout<<e[i]<<", ";
        }
        cout<<endl;
    }

    void quickSort::swap(int &e, int &f){
        int temp = e;
        e = f; 
        f = temp;
    }

    int quickSort::partition(int y[maxSize], int l, int h){
        int pivot = y[l];
        int i = l-1;
        
        for(int j = l; j<=h-1; j++){
            if(y[j]<pivot){
                i++;
                swap(y[i],y[j]);
            }
        }
        i++;
        swap(y[i],y[l]);

        return i;

    }

    void quickSort::quicksort(int e[maxSize], int l, int h){
        if (h<=l){
            return;
        }
        int pivot = partition(e, l, h);
        cout<<"qs"<<endl;
        quicksort(e, l, pivot-1);
        quicksort(e, pivot+1, h);

    }

    int main(){
        quickSort qs;
        qs.print(qs.x);
        qs.quicksort(qs.x, 0, maxSize-1);
        qs.print(qs.x);
        return 0;
    }