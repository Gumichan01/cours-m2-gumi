
(*
  Walgo.ml

  This file implements the W-algorithm

  Author : Luxon JEAN-PIERRE
*)

open ChurchType;;

type expression =
    Var of string
  | Const of string
  | Pair of expression * expression
  | Apply of expression * expression
  | Lambda of string * expression
  | Letin of string * expression * expression

type itype =
  | IBool
  | IInt
  | ICross of chtype * chtype
  | IArrow of chtype * chtype
  | IVar of tvar

and tvar = { id: int; mutable def: itype option}


type environment = string *

let rec infer_program : expression list -> ChurchType.chtype =
  failwith "TODO inference + W-algorithm"

let rec infer (env : environment) (e : expression) =
  match e with
  | Var(_) ->  (ChurchType.Int, [])(*failwith "TODO W-algorithm: Var"*)
  | Const(x) -> (inst(x), []) (* change it *)
  | Pair(_,_) -> failwith "TODO W-algorithm: Pair"
  | Apply(_,_) -> failwith "TODO W-algorithm: Apply"
  | Lambda(_,_) -> failwith "TODO W-algorithm: Lambda"
  | Letin(_,_,_) -> failwith "TODO W-algorithm: Letin"
  (*failwith "TODO W-algorithm"*)

and inst x =
  let inst_int s =
    try
      Some(int_of_string s)
    with
    | _ -> None
  in
  (
  match inst_int x with
  | Some(_) -> ChurchType.Int
  | None ->
    (match x with
     | "true" | "false" -> ChurchType.Bool
     | _ -> assert(false) (* Internal issue *)
    )
  )

(*
    Comment:

    - (TODO final goal) Apply the algorithm for each element of type chtype (an expression).
    - (TODO) Unify the expression if necessary
    - (DONE) Free and bound variables
    - (TODO) α-conversion

*)
