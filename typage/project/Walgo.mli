type expression =
    Var of string
  | Const of string
  | Pair of expression * expression
  | Apply of expression * expression
  | Lambda of string * expression
  | Letin of string * expression * expression
type itype =
    IBool
  | IInt
  | ICross of ChurchType.chtype * ChurchType.chtype
  | IArrow of ChurchType.chtype * ChurchType.chtype
  | IVar of tvar
and tvar = { id : int; mutable def : itype option; }
module V :
  sig
    type t = tvar
    val compare : tvar -> tvar -> int
    val equal : tvar -> tvar -> bool
    val create : unit -> tvar
  end
val math_ops : string list
val bool_ops : string list
type environment = (string * itype) list
val infer_program : expression list -> itype
val infer : environment -> expression -> itype * 'a list
val inst : environment -> expression -> itype
val inst_constv : string -> itype
val inst_intv : string -> int option
