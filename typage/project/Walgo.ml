
(*
  Walgo.ml

  This file implements the W-algorithm

  Author : Luxon JEAN-PIERRE
*)

open ChurchType;;

(* Expression to infer the type of *)
type expression =
    Var of string
  | Const of string
  | Pair of expression * expression
  | Apply of expression * expression
  | Lambda of string * expression
  | Letin of string * expression * expression

(* Type to infer *)
type itype =
  | IBool
  | IInt
  | ICross of chtype * chtype
  | IArrow of chtype * chtype
  | IVar of tvar

and tvar = { id: int; mutable def: itype option}

module V = struct
  type t = tvar
  let compare v1 v2 = Pervasives.compare v1.id v2.id
  let equal v1 v2 = v1.id = v2.id
  let create = let r = ref 0 in fun () -> incr r; { id = !r; def = None }
end

(* Typing environment *)
type environment = (string * itype) list

let rec infer_program : expression list -> itype =
  failwith "TODO inference + W-algorithm"

let rec infer (env : environment) (e : expression) =
  match e with
  | Var(_) | Const(_) as cv -> (inst env cv, [])
  | Pair(_,_) -> failwith "TODO W-algorithm: Pair"
  | Apply(_,_) -> failwith "TODO W-algorithm: Apply"
  | Lambda(_,_) -> failwith "TODO W-algorithm: Lambda"
  | Letin(_,_,_) -> failwith "TODO W-algorithm: Letin"
  (*failwith "TODO W-algorithm"*)

  and inst env = function
  | Var(s) -> List.assoc s env
  | Const(x) -> inst_constv x
  | _-> assert(false) (* instance of variable of value type *)

  and inst_constv x =
    (match inst_intv x with
     | Some(_) -> IInt
     | None ->
       (match x with
        | "true" | "false" -> IBool
        | _ -> assert(false) (* Internal issue *)
       )
    )
  and inst_intv s =
    try
      Some(int_of_string s)
    with
    | _ -> None



(*
    Comment:

    - (TODO final goal) Apply the algorithm for each element of type chtype (an expression).
    - (TODO) Unify the expression if necessary
    - (DONE) Free and bound variables
    - (TODO) α-conversion

*)
