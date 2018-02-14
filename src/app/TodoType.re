type todo = {
  id: int,
  text: string,
  completed: bool
};

type show =
  | Active
  | All
  | Completed;