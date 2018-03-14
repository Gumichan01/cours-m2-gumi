type expression =
    Var of string
  | Const of string
  | Pair of expression * expression
  | Apply of expression * expression
  | Lambda of string * expression
  | Letin of string * expression * expression
type itype = IBool | IInt | ICross of itype * itype | IArrow of itype * itype
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
val math_basictype : itype
val bool_basictype : itype
val lassoc_opt : 'a -> ('a * 'b) list -> 'b option
type environment = (string * itype) list
type unifier = (itype * itype) list
val infer_program : expression list -> itype
val infer : environment -> expression -> itype * unifier
val sigma : environment -> unifier -> environment
val sigma_in : environment -> unifier -> environment
val inst : environment -> expression -> itype
val inst_constv : string -> itype
val inst_intv : string -> int option
