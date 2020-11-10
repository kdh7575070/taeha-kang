function a(){
    let v_a = "a";

    function b(){
        let v_b = "b";
        console.log("b: ", typeof(v),typeof(v_a), typeof(v_b));
    }
    
    b();

    console.log("a: ", typeof(v),typeof(v_a), typeof(v_b));
}

let v="v";

a();

console.log("o: ", typeof(v),typeof(v_a), typeof(v_b));