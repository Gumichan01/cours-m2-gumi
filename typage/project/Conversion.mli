type substitution = string * string
type subList = substitution list
val assoc_if : 'a -> ('a * 'b) list -> 'b option
val alpha_conv :
  ChurchType.chexpression ->
  (string * string) list -> ChurchType.chexpression
val subs_var : string -> (string * string) list -> string
