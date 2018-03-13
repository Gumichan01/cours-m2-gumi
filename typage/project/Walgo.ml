
(*
  Walgo.ml

  This file implements the W-algorithm

  Author : Luxon JEAN-PIERRE
*)

open ChurchType;;

type environment = ()

let rec infer_program : ChurchType.chexpression list -> ChurchType.chtype =
  failwith "TODO inference + W-algorithm"

let rec infer (env : environment) (e : ChurchType.chexpression) =
  match e with
  | ChurchType.Var(_) -> failwith "TODO W-algorithm: Var"
  | ChurchType.Const(_) -> failwith "TODO W-algorithm: Const"
  | ChurchType.Pair(_,_) -> failwith "TODO W-algorithm: Pair"
  | ChurchType.Apply(_,_) -> failwith "TODO W-algorithm: Apply"
  | ChurchType.Lambda(_,_,_) -> failwith "TODO W-algorithm: Lambda"
  | ChurchType.Letin(_,_,_,_) -> failwith "TODO W-algorithm: Letin"
  (*failwith "TODO W-algorithm"*)



(*
    Comment:

    - (TODO final goal) Apply the algorithm for each element of type chtype (an expression).
    - (TODO) Unify the expression if necessary
    - (DONE) Free and bound variables
    - (TODO) α-conversion

*)
