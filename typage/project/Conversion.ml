
(*
  Conversion.ml

  This file handles alpha-conversion

  Author : Luxon JEAN-PIERRE
*)

open ChurchType;;

(*
  A substitution is just a pair <old_name, new_name> that represents {x / y}
  *)
type substitution = string * string;;

type subList = substitution list;;

(* miscelleanous function *)
let assoc_if a l =
  try
      Some(List.assoc a l)
  with
  | _ -> None


let rec free_variable = function
  | ChurchType.Var(s) -> [s]
  | ChurchType.Const(_) -> []
  | ChurchType.Pair(m, n)
  | ChurchType.Apply(m, n) -> (free_variable m) @ (free_variable n)
  | ChurchType.Lambda(_,_, m, _) -> (free_variable m) (* @ (free_variable n) *)
  | ChurchType.Letin(_,_, m, n)  -> (free_variable m) @ (free_variable n)


let rec bound_variable = function
  | ChurchType.Var(_)
  | ChurchType.Const(_) -> []
  | ChurchType.Pair(m, n)
  | ChurchType.Apply(m, n) -> (bound_variable m) @ (bound_variable n)
  | ChurchType.Lambda(x,_, m, _) -> (bound_variable m) @ [x] (* @ (bound_variable n) *)
  | ChurchType.Letin(x,_, m, n)  -> (bound_variable m) @ (bound_variable n) @ [x]

(*
  todo
  It operates the alpha-conversion by taking a church type and a substitution list
  to apply

  @note The function fails if a variable capture happened during the alpha-conversion
*)
let rec alpha_conv e env : chexpression =
  match e with
  | Var(s) ->
    let ns = subs_var s env in
    Var(ns)

  | Pair(e1, e2) -> Pair((alpha_conv e1 env), (alpha_conv e2 env))

  | Apply(e1, e2) -> Apply((alpha_conv e1 env), (alpha_conv e2 env))

  | _ -> failwith "TODO the rest"

  and subs_var s env =
    match assoc_if s env with
    | None      -> s
    | Some(sub) -> sub
;;


let che = Letin("w", Cross(Int, Cross(Int, Int)), Pair(Const("1"), Pair(Var("z"),Var("x"))), Var("w"));;
let env = ("x","y") :: ("z","w") :: [];;
(*let res = alpha_conv che env;;
pretty_print_e res; print_endline("");;*) (* alpha-conversion *)
print_string("\nFree variables \n\n");;
List.map (print_endline) ( List.tl (free_variable che) );; (* free_variable *)
print_string("\nBound variables \n\n");;
List.map (print_endline) (bound_variable che);; (* bound_variable *)
