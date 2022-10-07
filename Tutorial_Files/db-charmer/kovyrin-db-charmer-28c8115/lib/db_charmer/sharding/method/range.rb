module DbCharmer
  module Sharding
    module Method
      class Range
        attr_accessor :ranges

        def initialize(config)
          @ranges = config[:ranges] ? config[:ranges].clone : raise(ArgumentError, "No :ranges defined!")
        end

        def shard_for_key(key)
          return ranges[:default] if key == :default

          ranges.each do |range, shard|
            next if range == :default
            return shard if range.member?(key.to_i)
          end

          return ranges[:default] if ranges[:default]
          raise ArgumentError, "Invalid key value, no shards found for this key!"
        end

        def support_default_shard?
          ranges.has_key?(:default)
        end
      end
    end
  end
end
