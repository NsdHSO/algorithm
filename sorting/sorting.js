function sorting(array){
	for (let i = 0; i < array.length; i++) {
		var lower = i;
		for (let j = i+1; j < array.length ; j++) {
			if(array[j] < array[lower]){
				lower = j;
				}
		}
		if(lower !== i ){

		swap(array,i ,lower )			
	}}
	console.log(array)
	return array
}


let a = [3,2,1,6,22,41,12];
sorting(a)
function bubble(array){
	for (let i = array.length ; i > 0 ; i--) {
		for (let j = 0; j < i-1; j++) {
			if(array[j] > array[j+1]){
				swap(array, j, j+1);

			}
		}	
	}
	return array;
}

console.log(a)

function swap(jSingle, jIncrement){
	let temp = jSingle
	jSingle = jIncrement
	jIncrement = temp
}
a.push(4)
a.push(10)
a.push(13)

function swap(array, first, swap){
	let temp = array[first];
	array[first] = array[swap]
	array[swap] = temp
}

console.log(bubble(a));

