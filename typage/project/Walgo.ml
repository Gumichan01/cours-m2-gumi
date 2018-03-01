
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
  failwith "TODO W-algorithm"



(*
    Comment:

    - (TODO final goal) Apply the algorithm for each element of type chtype (an expression).
    - (TODO) Unify the expression if necessary
    - (TODO) Free and bound variables
    - (TODO) α-conversion

*)
