function binary(array, item){
    let low, mid, hight;
    low = 0;
    hight = array.length - 1
    while( low <= hight){
        mid = (low + hight ) / 2
        if(item === array[mid]){
            return mid
        }
        else if(item < array[mid]) 
        {
            hight = mid - 1 
        }
        else {
            low = mid + 1 
        }
    }
    return -1;
}

let a = [14,5,1,6,3,1,33,67,234,2,51]

console.log(binary(a, 6))

console.log("Sami")
