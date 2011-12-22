/*
 * LibCassandra
 * Copyright (C) 2010-2011 Padraig O'Sullivan
 * All rights reserved.
 *
 * Use and distribution licensed under the BSD license. See
 * the COPYING file in the parent directory for full text.
 */

#include <string>
#include <vector>
#include <map>

#include "libcassandra/column_family_definition.h"
#include "libcassandra/column_definition.h"

using namespace libcassandra;
using namespace std;
using namespace org::apache::cassandra;


ColumnFamilyDefinition::ColumnFamilyDefinition()
  :
    keyspace_name(),
    name(),
    column_type("Standard"),
    comparator_type(),
    sub_comparator_type(),
    comment(),
    row_cache_size(0),
    key_cache_size(200000),
    read_repair_chance(1),
    gc_grace_seconds(864000),
    default_validation_class(),
    id(0),
    min_compaction_threshold(4),
    max_compaction_threshold(22),
    row_cache_save_period_in_seconds(0),
    key_cache_save_period_in_seconds(0),
    replicate_on_write(true),
    merge_shards_chance(0.0),
    key_validation_class(""),
    row_cache_provider("org.apache.cassandra.cache.ConcurrentLinkedHashCacheProvider"),
    key_alias(""),
    compaction_strategy_options(),
    row_cache_keys_to_save(0),
    column_metadata()
{}


ColumnFamilyDefinition::ColumnFamilyDefinition(const string& in_keyspace_name,
                                               const string& in_name,
                                               const string& in_column_type,
                                               const string& in_comparator_type,
                                               const string& in_sub_comparator_type,
                                               const string& in_comment,
                                               const double in_row_cache_size,
                                               const double in_key_cache_size,
                                               const double in_read_repair_chance,
                                               vector<ColumnDef>& in_column_metadata,
                                               const int32_t in_gc_grace_seconds,
                                               const string& in_default_validation_class,
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
                                               const std::map<std::string, std::string> in_compression_options) 
  :
    keyspace_name(in_keyspace_name),
    name(in_name),
    column_type(in_column_type),
    comparator_type(in_comparator_type),
    sub_comparator_type(in_sub_comparator_type),
    comment(in_comment),
    row_cache_size(in_row_cache_size),
    key_cache_size(in_key_cache_size),
    read_repair_chance(in_read_repair_chance),
    gc_grace_seconds(in_gc_grace_seconds),
    default_validation_class(in_default_validation_class),
    id(in_id),
    min_compaction_threshold(in_min_compaction_threshold),
    max_compaction_threshold(in_max_compaction_threshold),
    row_cache_save_period_in_seconds(in_row_cache_save_period_in_seconds),
    key_cache_save_period_in_seconds(in_key_cache_save_period_in_seconds),
    replicate_on_write(in_replicate_on_write),
    merge_shards_chance(in_merge_shards_chance),
    key_validation_class(in_key_validation_class),
    row_cache_provider(in_row_cache_provider),
    key_alias(in_key_alias),
    compaction_strategy_options(in_compaction_strategy_options),
    row_cache_keys_to_save(in_row_cache_keys_to_save),
    column_metadata()
{
  for (vector<ColumnDef>::iterator it= in_column_metadata.begin();
       it != in_column_metadata.end();
       ++it)
  {
    ColumnDef thrift_entry= *it;
    ColumnDefinition entry(thrift_entry.name,
                           thrift_entry.validation_class,
                           thrift_entry.index_type,
                           thrift_entry.index_name,
                           thrift_entry.index_options);

    column_metadata.push_back(entry);
  }
}


string ColumnFamilyDefinition::getName() const
{
  return name;
}


void ColumnFamilyDefinition::setName(const string& cf_name)
{
  name.assign(cf_name);
}


string ColumnFamilyDefinition::getKeyspaceName() const
{
  return keyspace_name;
}


void ColumnFamilyDefinition::setKeyspaceName(const string& ks_name)
{
  keyspace_name.assign(ks_name);
}


string ColumnFamilyDefinition::getColumnType() const
{
  return column_type;
}


void ColumnFamilyDefinition::setColumnType(const string& col_type)
{
  column_type.assign(col_type);
}


bool ColumnFamilyDefinition::isColumnTypeSet() const
{
  return (! column_type.empty());
}


string ColumnFamilyDefinition::getComparatorType() const
{
  return comparator_type;
}


void ColumnFamilyDefinition::setComparatorType(const string& comp_type)
{
  comparator_type.assign(comp_type);
}


bool ColumnFamilyDefinition::isComparatorTypeSet() const
{
  return (! comparator_type.empty());
}


string ColumnFamilyDefinition::getSubComparatorType() const
{
  return sub_comparator_type;
}


void ColumnFamilyDefinition::setSubComparatorType(const string& sub_comp_type)
{
  sub_comparator_type.assign(sub_comp_type);
}


bool ColumnFamilyDefinition::isSubComparatorTypeSet() const
{
  return (! sub_comparator_type.empty());
}


string ColumnFamilyDefinition::getComment() const
{
  return comment;
}


void ColumnFamilyDefinition::setComment(const string& comm)
{
  comment.assign(comm);
}


bool ColumnFamilyDefinition::isCommentSet() const
{
  return (! comment.empty());
}


double ColumnFamilyDefinition::getRowCacheSize() const
{
  return row_cache_size;
}


void ColumnFamilyDefinition::setRowCacheSize(double size)
{
  row_cache_size= size;
}


bool ColumnFamilyDefinition::isRowCacheSizeSet() const
{
  return (row_cache_size > 0 ? true : false);
}


int32_t ColumnFamilyDefinition::getRowCacheSavePeriod() const
{
  return row_cache_save_period_in_seconds;
}


void ColumnFamilyDefinition::setRowCacheSavePeriod(int32_t save_period)
{
  row_cache_save_period_in_seconds= save_period;
}


bool ColumnFamilyDefinition::isRowCacheSavePeriodSet() const
{
  return (row_cache_save_period_in_seconds > 0 ? true : false);
}


double ColumnFamilyDefinition::getKeyCacheSize() const
{
  return key_cache_size;
}


void ColumnFamilyDefinition::setKeyCacheSize(double size)
{
  key_cache_size= size;
}


bool ColumnFamilyDefinition::isKeyCacheSizeSet() const
{
  return (key_cache_size > 0 ? true : false);
}

void ColumnFamilyDefinition::setKeyCacheSavePeriod(int32_t save_period)
{
  key_cache_save_period_in_seconds = save_period;
}

int32_t ColumnFamilyDefinition::getKeyCacheSavePeriod() const
{
  return key_cache_save_period_in_seconds;
}

bool ColumnFamilyDefinition::isKeyCacheSavePeriodSet() const
{
  return (key_cache_save_period_in_seconds > 0 ? true : false);
}

double ColumnFamilyDefinition::getReadRepairChance() const
{
  return read_repair_chance;
}


void ColumnFamilyDefinition::setReadRepairChance(double chance)
{
  read_repair_chance= chance;
}


bool ColumnFamilyDefinition::isReadRepairChanceSet() const
{
  return (read_repair_chance > 0 ? true : false);
}


int32_t ColumnFamilyDefinition::getGcGraceSeconds() const
{
  return gc_grace_seconds;
}


void ColumnFamilyDefinition::setGcGraceSeconds(int32_t gc_secs)
{
  gc_grace_seconds= gc_secs;
}


bool ColumnFamilyDefinition::isGcGraceSecondsSet() const
{
  return (gc_grace_seconds > 0 ? true : false);
}


string ColumnFamilyDefinition::getDefaultValidationClass() const
{
  return default_validation_class;
}


void ColumnFamilyDefinition::setDefaultValidationClass(const string& class_name)
{
  default_validation_class.assign(class_name);
}


bool ColumnFamilyDefinition::isDefaultValidationClassSet() const
{
  return (! default_validation_class.empty());
}

int32_t ColumnFamilyDefinition::getId() const
{
  return id;
}

void ColumnFamilyDefinition::setId(int32_t new_id)
{
  id= new_id;
}

bool ColumnFamilyDefinition::isIdSet() const
{
  return (id > 0 ? true : false);
}

int32_t ColumnFamilyDefinition::getMaxCompactionThreshold() const
{
  return max_compaction_threshold;
}

void ColumnFamilyDefinition::setMaxCompactionThreshold(int32_t threshold)
{
  max_compaction_threshold= threshold;
}

bool ColumnFamilyDefinition::isMaxCompactionThresholdSet() const
{
  return (max_compaction_threshold > 0 ? true : false);
}

int32_t ColumnFamilyDefinition::getMinCompactionThreshold() const
{
  return min_compaction_threshold;
}

void ColumnFamilyDefinition::setMinCompactionThreshold(int32_t threshold)
{
  min_compaction_threshold= threshold;
}

bool ColumnFamilyDefinition::isMinCompactionThresholdSet() const
{
  return (min_compaction_threshold > 0 ? true : false);
}

void ColumnFamilyDefinition::setReplicateOnWrite(bool replicate_on_write) 
{
  this->replicate_on_write = replicate_on_write;
}

bool ColumnFamilyDefinition::getReplicateOnWrite() const 
{
  return replicate_on_write;
}

bool ColumnFamilyDefinition::isReplicateOnWriteSet() const
{
  return !replicate_on_write;
}

void ColumnFamilyDefinition::setMergeShardsChance(double in_merge_shards_chance) 
{
  this->merge_shards_chance = in_merge_shards_chance;
}

double ColumnFamilyDefinition::getMergeShardsChance() const
{
  return merge_shards_chance;
}

bool ColumnFamilyDefinition::isMergeShardsChanceSet() const 
{
  return merge_shards_chance != 0.0;
}

void ColumnFamilyDefinition::setKeyValidationClass(const std::string &in_key_validation_class) 
{
  this->key_validation_class = in_key_validation_class;
}

std::string ColumnFamilyDefinition::getKeyValidationClass() const
{
  return key_validation_class;
}

bool ColumnFamilyDefinition::isKeyValidationClassSet() const
{
  return key_validation_class != "";
}

void ColumnFamilyDefinition::setRowCacheProvider(const std::string &in_row_cache_provider)
{
  this->row_cache_provider = in_row_cache_provider;
}

std::string ColumnFamilyDefinition::getRowCacheProvider() const
{
  return row_cache_provider;
}

bool ColumnFamilyDefinition::isRowCacheProviderSet() const
{
  return row_cache_provider != "org.apache.cassandra.cache.ConcurrentLinkedHashCacheProvider";
}

void ColumnFamilyDefinition::setKeyAlias(const std::string &in_key_alias) 
{
  this->key_alias = in_key_alias;
}

std::string ColumnFamilyDefinition::getKeyAlias() const 
{
  return key_alias;
}

bool ColumnFamilyDefinition::isKeyAliasSet() const
{
  return !key_alias.empty();
}

void ColumnFamilyDefinition::setCompactionStrategy(const std::string &in_compaction_strategy)
{
  this->compaction_strategy = in_compaction_strategy;
}

std::string ColumnFamilyDefinition::getCompactionStrategy() const 
{
  return compaction_strategy;
}

bool ColumnFamilyDefinition::isCompactionStrategySet() const 
{
  return !compaction_strategy.empty();
}

void ColumnFamilyDefinition::setCompactionStrategyOptions(const std::map<std::string, std::string> &in_compaction_strategy_options)
{
  this->compaction_strategy_options = in_compaction_strategy_options;
}

std::map<std::string, std::string> ColumnFamilyDefinition::getCompactionStrategyOptions() const
{
  return compaction_strategy_options;
}

bool ColumnFamilyDefinition::isCompactionStrategyOptionsSet() const
{
  return !compaction_strategy_options.empty();
}

void ColumnFamilyDefinition::setRowCacheKeysToSave(int32_t in_row_cache_keys_to_save)
{
  this->row_cache_keys_to_save = in_row_cache_keys_to_save;
}

int32_t ColumnFamilyDefinition::getRowCacheKeysToSave() const
{
  return row_cache_keys_to_save;
}

bool ColumnFamilyDefinition::isRowCacheKeysToSaveSet() const
{
  return row_cache_keys_to_save != 0;
}

void ColumnFamilyDefinition::setCompressionOptions(const std::map<std::string, std::string> &in_compression_options)
{
  this->compression_options = in_compression_options;
}
  
std::map<std::string, std::string> ColumnFamilyDefinition::getCompressionOptions() const
{
  return compression_options;
}

bool ColumnFamilyDefinition::isCompressionOptionsSet() const
{
  return !compression_options.empty();
}

vector<ColumnDefinition> ColumnFamilyDefinition::getColumnMetadata() const
{
  return column_metadata;
}

void ColumnFamilyDefinition::setColumnMetadata(const vector<ColumnDefinition>& meta)
{
  column_metadata.clear();
  for (vector<ColumnDefinition>::const_iterator it= meta.begin();
       it != meta.end();
       ++it)
  {
    column_metadata.push_back(*it);
  }
}

void ColumnFamilyDefinition::addColumnMetadata(const ColumnDefinition& col_meta)
{
  column_metadata.push_back(col_meta);
}

bool ColumnFamilyDefinition::isColumnMetadataSet() const
{
  return (! column_metadata.empty());
}

