type expression =
    Var of string
  | Const of string
  | Pair of expression * expression
  | Apply of expression * expression
  | Lambda of string * expression
  | Letin of string * expression * expression
type environment = ()
val infer_program : expression list -> ChurchType.chtype
val infer : environment -> expression -> ChurchType.chtype * 'a list
val inst : string -> ChurchType.chtype
