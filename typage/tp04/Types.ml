
let y = (fun f -> (fun x -> f x x) (fun x -> f x x) );;

let rec fact n = if n == 0 then 1 else n * fact (n - 1);;
let f y n = if n == 0 then 1 else  n * y (n - 1);;
  
let rec fix1 f = f (fix f);;
let rec fix2 f x = f (fix2 f) x;;

  
let factx = fix2 f;;
factx 6;;
