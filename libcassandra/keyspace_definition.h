/*
 * LibCassandra
 * Copyright (C) 2010-2011 Padraig O'Sullivan
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license. See
 * the COPYING file in the parent directory for full text.
 */

#ifndef __LIBCASSANDRA_KEYSPACE_DEFINITION_H
#define __LIBCASSANDRA_KEYSPACE_DEFINITION_H

#include <string>
#include <map>
#include <vector>

#include "libgenthrift/cassandra_types.h"

#include "libcassandra/column_family_definition.h"

namespace libcassandra
{

class Cassandra;

class KeyspaceDefinition
{

public:

  KeyspaceDefinition();
  KeyspaceDefinition(const std::string& in_name,
                     const std::string& in_strategy_class,
                     const std::map<std::string, std::string>& in_strategy_options,
                     const int32_t in_replication_factor,
                     std::vector<org::apache::cassandra::CfDef>& in_cf_defs,
                     bool durable_writes);

  ~KeyspaceDefinition() {}

  /**
   * @return keyspace name
   */
  std::string getName() const;

  void setName(const std::string& ks_name);

  /**
   * @return strategy class name for this keyspace
   */
  std::string getStrategyClass() const;

  void setStrategyClass(const std::string& strat_class);

  /**
   * @return strategy options for this keyspace
   */
  std::map<std::string, std::string> getStrategyOptions() const;

  void setStrategyOptions(const std::map<std::string, std::string>& opts);

  /**
   * @return replication factor for this keyspace
   */
  int32_t getReplicationFactor() const;

  void setReplicationFactor(int32_t rep_factor);

  /**
   * @return the column families in this keyspace
   */
  std::vector<ColumnFamilyDefinition> getColumnFamilies() const;

  void setColumnFamilies(std::vector<ColumnFamilyDefinition>& cfs);

  /**
   * @return durable writes 
   *
   * Durability is the property that writes, once completed, will survive 
   * permanently even in the face of hardware failure. Cassandra provides 
   * configurable durability by appending writes to a commit log first (which 
   * obviates the need for disk seeks since this is a sequential operation), 
   * then uses the fsync system call to flush the data to disk.
   *
   * @see http://www.datastax.com/docs/1.0/introduction/index
   *
   */
  bool getDurableWrites() const;
  
  void setDurableWrites(bool dwrites);

private:

  std::string name;

  std::string strategy_class;

  std::map<std::string, std::string> strategy_options;

  int32_t replication_factor;

  std::vector<ColumnFamilyDefinition> col_family_defs;

  bool durable_writes;

};

} /* end namespace libcassandra */

#endif /* __LIBCASSANDRA_KEYSPACE_DEFINITION_H */
