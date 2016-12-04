/*
** main.c for the_parser_example in sources
**
** Made by
** Login   <@epitech.net>
**
** Started on  Thu Dec 01 15:12:09 2016
** Last update Sun Dec 04 15:28:32 2016 Benoit Hamon
*/

#include <stdbool.h>
#include <stdio.h>
#include "tools/tools.h"
#include "the_parser/parser.h"

int		main(int argc, char const* argv[])
{
  void		*grammar;
  char		*str;
  t_return	parse;
  int		i;

  if (argc != 2)
  {
    dprintf(2, "Usage: %s grammar\n", argv[0]);
    return (1);
  }
  grammar = init_parser(argv[1], 1);
  while ((str = get_next_line(0)))
  {
    parse = launch_parser(grammar, str, &i);
    if (parse.ok && !str[i])
      print_parse(parse.graph, 0);
    else
      dprintf(2, "Syntax Error\n");
    the_free(2, FREE_GRAPH, parse.graph, FREE_STR, str);
  }
  end_parser(grammar);
  return (0);
}
