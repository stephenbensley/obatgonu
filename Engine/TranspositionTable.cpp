//
// Copyright 2023 Stephen E. Bensley
//
// This file is licensed under the MIT License. You may obtain a copy of the
// license at https://github.com/stephenbensley/obatgonu/blob/main/LICENSE.
//

#include "TranspositionTable.h"
#include "Graph.h"

TranspositionTable::TranspositionTable(const Graph& graph)
: graph_(graph)
{
   value_.resize(graph.size());
}

std::optional<int> TranspositionTable::find(const Node& node) const noexcept
{
   auto value = value_[graph_.index(node)];
   if (value == 0) {
      return {};
   }
   return value;
}

void TranspositionTable::insert(const Node& node, int value) noexcept
{
   value_[graph_.index(node)] = value;
}
