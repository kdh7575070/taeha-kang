function push(typing){
    var input=document.getElementById("input");
    input.value+=typing;
}
function calculate(){
    var input=document.getElementById("input");
    var result=eval(input.value);
    input.value=result;
}
function clean(){
    var input=document.getElementById("input");
    input.value="";
}