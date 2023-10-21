class BubbleSort {
    #array = [];
    constructor(array) {
        this.#array = array;
    }

    #swap(i, j){
        let temp = this.#array[j];
        this.#array[j] = this.#array[i];
        this.#array[i] = temp;
    }

    sort() {
        let n = this.#array.length;
        let swapped = false;

        for(let i=0; i<n-1; i++) {
            swapped = false;
            for(let j=0; j<n-1-i; j++) {
                if(this.#array[j] > this.#array[j+1]){
                    this.#swap(j, j+1);
                    swapped = true;
                }
            }

            if(swapped == false) break;
        }

        return this.#array;
    }
}

arr = [6,3,0,5,-1];

let bubbleSort = new BubbleSort(arr);
console.log(bubbleSort.sort());