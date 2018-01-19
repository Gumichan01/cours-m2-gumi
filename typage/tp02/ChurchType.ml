


type chtype =
    Bool
  | Int
  | Cross of chtype * chtype
  | Arrow of chtype * chtype;;

type chexpression =
    Var of string
  | Const of string
  | Pair of chexpression * chexpression
  | Apply of chexpression * chexpression
  | Lambda of string * chtype * chexpression * chexpression
  | Letin of string * chtype * chexpression * chexpression

type environment = (string * chtype) list;;

let tc =
  function
  | Const(s) -> Bool (* TODO this function *)
  | _ -> failwith "tc: invalid argument"

let rec type_check (env: environment) expression =
 match expression with
 | Const _       -> tc expression
 | Var s         -> List.assoc s env
 | Pair(a1, a2)  ->
   let t1 = type_check env a1 in
   let t2 = type_check env a2 in Cross(t1, t2)
 | Apply _       -> failwith "todo apply"
 | Lambda _  -> failwith "todo lambda"
 | Letin(x, t, e1, e2) ->
   match t == (type_check env e1) with
   | false -> failwith "type checking: invalid type"
   | _ -> let nenv = (x, t)::env in (type_check nenv e2)
