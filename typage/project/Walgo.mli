type environment = ()
val infer_program : ChurchType.chexpression list -> ChurchType.chtype
val infer : environment -> ChurchType.chexpression -> 'a
