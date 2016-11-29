var addOne = (x) => x + 1;
var sqrt = (x) => x * x;
var log = (x) => console.log(x);

function compose(){

}

addOneSqrtAndPrint = compose(log, sqrt, addOne);

addOneSqrtAndPrint(1); // 4