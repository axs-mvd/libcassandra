/*
 * LibCassandra
 * Copyright (C) 2010-2011 Padraig O'Sullivan
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license. See
 * the COPYING file in the parent directory for full text.
 */

#ifndef __LIBCASSANDRA_COLUMN_FAMILY_DEFINITION_H
#define __LIBCASSANDRA_COLUMN_FAMILY_DEFINITION_H

#include <string>
#include <map>
#include <vector>

#include "libgenthrift/cassandra_types.h"

#include "libcassandra/column_definition.h"

namespace libcassandra
{

class Cassandra;

class ColumnFamilyDefinition
{

public:

  ColumnFamilyDefinition();
  ColumnFamilyDefinition(const std::string& in_keyspace_name,
                         const std::string& in_name,
                         const std::string& in_column_type,
                         const std::string& in_comparator_type,
                         const std::string& in_sub_comparator_type,
                         const std::string& in_comment,
                         const double in_row_cache_size,
                         const double in_key_cache_size,
                         const double in_read_repair_chance,
                         std::vector<org::apache::cassandra::ColumnDef>& in_column_metadata,
                         const int32_t in_gc_grace_seconds,
                         const std::string& in_default_validation_class,
                         const int32_t in_id,
                         const int32_t in_min_compaction_threshold,
                         const int32_t in_max_compaction_threshold,
                         const int32_t in_row_cache_save_period_in_seconds,
                         const int32_t in_key_cache_save_period_in_seconds,
                         const bool in_replicate_on_write,
                         const double in_merge_shards_chance,
                         const std::string in_key_validation_class,
                         const std::string in_row_cache_provider,
                         const std::string in_key_alias,
                         const std::string in_compaction_strategy,
                         const std::map<std::string, std::string> in_compaction_strategy_options,
                         const int32_t in_row_cache_keys_to_save,
                         const std::map<std::string, std::string> in_compression_options);
 
  ~ColumnFamilyDefinition() {}

  /**
   * @return column family name
   */
  std::string getName() const;

  void setName(const std::string& cf_name);

  /**
   * @return keyspace name
   */
  std::string getKeyspaceName() const;

  void setKeyspaceName(const std::string& ks_name);

  /**
   * @return column type
   */
  std::string getColumnType() const;

  void setColumnType(const std::string& col_type);

  /**
   * @return true if column type is set; false otherwise
   */
  bool isColumnTypeSet() const;

  /**
   * @return comparator type
   */
  std::string getComparatorType() const;

  void setComparatorType(const std::string& comp_type);

  /**
   * @return true if comparator type is set; false otherwise
   */
  bool isComparatorTypeSet() const;

  /**
   * @return sub-comparator type
   */
  std::string getSubComparatorType() const;

  void setSubComparatorType(const std::string& sub_comp_type);

  /**
   * @return true if sub comparator type is set; false otherwise
   */
  bool isSubComparatorTypeSet() const;

  /**
   * @return comment
   */
  std::string getComment() const;

  void setComment(const std::string& comm);

  /**
   * @return true if comment is set; false otherwise
   */
  bool isCommentSet() const;

  /**
   * @return row cache size
   */
  double getRowCacheSize() const;

  void setRowCacheSize(double size);

  /**
   * @return true if row cache size is > 0; false otherwise
   */
  bool isRowCacheSizeSet() const;

  /**
   * @return row cache save period in seconds
   */
  int32_t getRowCacheSavePeriod() const;

  void setRowCacheSavePeriod(int32_t save_period);

  /**
   * @return true if row cache save period is > 0; false otherwise
   */
  bool isRowCacheSavePeriodSet() const;

  /**
   * @return key cache size
   */
  double getKeyCacheSize() const;

  void setKeyCacheSize(double size);

  /**
   * @return key cache save period in seconds
   */
  int32_t getKeyCacheSavePeriod() const;

  void setKeyCacheSavePeriod(int32_t save_period);

  /**
   * @return true if key cache save period > 0; false otherwise
   */
  bool isKeyCacheSavePeriodSet() const;

  /**
   * @return true if key cache size is > 0; false otherwise
   */
  bool isKeyCacheSizeSet() const;

  /**
   * @return read repair chance
   */
  double getReadRepairChance() const;

  void setReadRepairChance(double chance);

  /**
   * @return true if read repair chance > 0; false otherwise
   */
  bool isReadRepairChanceSet() const;

  /**
   * @return garbage collection grace seconds
   */
  int32_t getGcGraceSeconds() const;

  void setGcGraceSeconds(int32_t gc_secs);

  /**
   * @return true if gc grace seconds > 0; false otherwise
   */
  bool isGcGraceSecondsSet() const;

  /**
   * @return default validation class
   */
  std::string getDefaultValidationClass() const;

  void setDefaultValidationClass(const std::string& class_name);

  /**
   * @return true if default validation class is set; false otherwise
   */
  bool isDefaultValidationClassSet() const;

  /**
   * @return column family ID
   */
  int32_t getId() const;

  void setId(int32_t new_id);

  /**
   * @return true if id > 0; false otherwise
   */
  bool isIdSet() const;

  /**
   * @return max compaction threshold
   */
  int32_t getMaxCompactionThreshold() const;

  void setMaxCompactionThreshold(int32_t threshold);

  /**
   * @return true if max compaction threshold > 0; false otherwise
   */
  bool isMaxCompactionThresholdSet() const;

  /**
   * @return min compaction threshold
   */
  int32_t getMinCompactionThreshold() const;

  void setMinCompactionThreshold(int32_t threshold);

  /**
   * @return true if min compaction threshold > 0; false otherwise
   */
  bool isMinCompactionThresholdSet() const;

  /** arranco acá*/

  void setReplicateOnWrite(bool replicate_on_write);

  bool getReplicateOnWrite() const;

  bool isReplicateOnWriteSet() const;

  void setMergeShardsChance(double merge_shards_chance);
  
  double getMergeShardsChance() const;
  
  bool isMergeShardsChanceSet() const;

  void setKeyValidationClass(const std::string &key_validation_class);

  std::string getKeyValidationClass() const;

  bool isKeyValidationClassSet() const;

  void setRowCacheProvider(const std::string &row_cache_provider);

  std::string getRowCacheProvider() const;

  bool isRowCacheProviderSet() const;

  void setKeyAlias(const std::string &key_alias);

  std::string getKeyAlias() const;

  bool isKeyAliasSet() const;

  void setCompactionStrategy(const std::string &compaction_strategy);

  std::string getCompactionStrategy() const;

  bool isCompactionStrategySet() const;

  void setCompactionStrategyOptions(const std::map<std::string, std::string> &strategy_options);
  
  std::map<std::string, std::string> getCompactionStrategyOptions() const;

  bool isCompactionStrategyOptionsSet() const;

  void setRowCacheKeysToSave(int32_t row_cache_keys_to_save);

  int32_t getRowCacheKeysToSave() const;

  bool isRowCacheKeysToSaveSet() const;

  /* por acá deberías ir parando manolo */
  std::vector<ColumnDefinition> getColumnMetadata() const;

  void setColumnMetadata(const std::vector<ColumnDefinition>& meta);

  void addColumnMetadata(const ColumnDefinition& col_meta);

  bool isColumnMetadataSet() const;

private:

  std::string keyspace_name;

  std::string name;

  std::string column_type;

  std::string comparator_type;

  std::string sub_comparator_type;

  std::string comment;

  double row_cache_size;

  double key_cache_size;

  double read_repair_chance;

  int32_t gc_grace_seconds;

  std::string default_validation_class;

  int32_t id;

  int32_t min_compaction_threshold;

  int32_t max_compaction_threshold;

  int32_t row_cache_save_period_in_seconds;

  int32_t key_cache_save_period_in_seconds;

/**new shit*/

  bool replicate_on_write;
  
  double merge_shards_chance;

  std::string key_validation_class;

  std::string row_cache_provider;

  std::string key_alias;

  std::string compaction_strategy;

  std::map<std::string, std::string> compaction_strategy_options;
  
  int32_t row_cache_keys_to_save;

  std::map<std::string, std::string> compression_options;
  
  std::vector<ColumnDefinition> column_metadata;

};

} /* end namespace libcassandra */

#endif /* __LIBCASSANDRA_COLUMN_FAMILY_DEFINITION_H */
