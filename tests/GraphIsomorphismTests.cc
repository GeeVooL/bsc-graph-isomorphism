#include "Graph.h"

#include <boost/test/unit_test.hpp>
#include <boost/mpl/list.hpp>

using namespace graph;

BOOST_AUTO_TEST_SUITE(GraphIsomorphismTests)

BOOST_AUTO_TEST_CASE(WhenConstructed_VertexesCount)
{
  Graph g(2);
  Graph h(4);

  BOOST_CHECK(g.Size() == 2);
  BOOST_CHECK(h.Size() == 4);
}

BOOST_AUTO_TEST_CASE(WhenConstructed_ThenEdgesCountIsZero)
{
  Graph g(3);

  BOOST_CHECK(g.GetEdgesCount() == 0);
}

BOOST_AUTO_TEST_CASE(WhenEdgeInserted_ThenEdgesCountIncremented)
{
  Graph g(3);

  g.AddEdge(1, 2);

  BOOST_CHECK(g.GetEdgesCount() == 1);
}

BOOST_AUTO_TEST_CASE(WhenSeveralEdgesInserted_ThenEdgesCountIsValid)
{
  Graph g(3);

  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 0);

  BOOST_CHECK(g.GetEdgesCount() == 3);
}

BOOST_AUTO_TEST_CASE(WhenInvalidEdge_ThenReturnFalse)
{
  Graph g(3);

  BOOST_CHECK(!g.AddEdge(2, 3));
}

BOOST_AUTO_TEST_CASE(WhenDoubledEdge_ThenReturnFalse)
{
  Graph g(3);
  g.AddEdge(2, 3);

  BOOST_CHECK(!g.AddEdge(2, 3));
}

BOOST_AUTO_TEST_CASE(CheckIsomorphism1_WhenSizeNotEqual)
{
  Graph g(4);
  Graph h(3);

  std::vector<size_t> dummy;
  BOOST_CHECK(!g.AreIsomorphic(h, dummy));
}

BOOST_AUTO_TEST_CASE(CheckIsomorphism_WhenEdgesCountNotEqual)
{
  Graph g(4);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);

  Graph h(4);
  h.AddEdge(1, 2);
  h.AddEdge(2, 3);

  std::vector<size_t> dummy;
  BOOST_CHECK(!g.AreIsomorphic(h, dummy));
}

BOOST_AUTO_TEST_CASE(CheckIsomorphism1)
{
  Graph g(4);
  Graph h(4);

  std::vector<size_t> dummy;
  BOOST_CHECK(g.AreIsomorphic(h, dummy));
}

BOOST_AUTO_TEST_CASE(CheckIsomorphism2)
{
  Graph g(4);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);

  Graph h(4);
  h.AddEdge(1, 2);
  h.AddEdge(2, 3);
  h.AddEdge(3, 0);

  std::vector<size_t> dummy;
  BOOST_CHECK(g.AreIsomorphic(h, dummy));
}

BOOST_AUTO_TEST_CASE(CheckIsomorphism3)
{
  Graph g(4);
  g.AddEdge(0, 1);
  g.AddEdge(1, 2);
  g.AddEdge(2, 3);
  g.AddEdge(3, 0);
  g.AddEdge(3, 1);

  Graph h(4);
  h.AddEdge(1, 3);
  h.AddEdge(3, 2);
  h.AddEdge(2, 0);
  h.AddEdge(0, 1);
  h.AddEdge(1, 2);

  std::vector<size_t> dummy;
  BOOST_CHECK(g.AreIsomorphic(h, dummy));
}

BOOST_AUTO_TEST_SUITE_END()