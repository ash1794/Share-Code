import math
from typing import List
import mmh3  # murmurhash3 for better hash function distribution

class BloomFilter:
    def __init__(self, size: int, num_hash_functions: int):
        """
        Initialize a Bloom filter with a given size and number of hash functions.
        
        Args:
            size: The size of the bit array
            num_hash_functions: Number of hash functions to use
        """
        self.size = size
        self.num_hash_functions = num_hash_functions
        self.bit_array = [0] * size
    
    def _get_hash_values(self, item: str) -> List[int]:
        """
        Generate hash values for an item using multiple hash functions.
        We use the murmurhash3 algorithm with different seeds for better distribution.
        """
        return [
            mmh3.hash(str(item), seed=i) % self.size 
            for i in range(self.num_hash_functions)
        ]
    
    def add(self, item: str) -> None:
        """Add an item to the Bloom filter."""
        for index in self._get_hash_values(item):
            self.bit_array[index] = 1
    
    def contains(self, item: str) -> bool:
        """
        Check if an item might be in the set.
        Returns False if item definitely isn't in set, True if it might be.
        """
        return all(
            self.bit_array[index] == 1 
            for index in self._get_hash_values(item)
        )
    
    @staticmethod
    def get_optimal_params(num_items: int, false_positive_rate: float) -> tuple:
        """
        Calculate optimal size and number of hash functions given desired error rate.
        
        Args:
            num_items: Expected number of items to store
            false_positive_rate: Desired false positive rate
            
        Returns:
            tuple: (optimal_size, optimal_num_hash_functions)
        """
        optimal_size = int(
            -(num_items * math.log(false_positive_rate)) / (math.log(2) ** 2)
        )
        optimal_num_hash = int(
            (optimal_size / num_items) * math.log(2)
        )
        return optimal_size, optimal_num_hash

# Example usage and analysis
def demonstrate_bloom_filter():
    # Create a Bloom filter optimized for 10000 items with 1% false positive rate
    size, num_hash = BloomFilter.get_optimal_params(100000, 0.01)
    bloom = BloomFilter(size, num_hash)
    
    # Add some items
    words = ["apple", "banana", "cherry"]
    for word in words:
        bloom.add(word)
    
    # Test membership
    test_words = ["apple", "banana", "dragonfruit"]
    for word in test_words:
        result = bloom.contains(word)
        print(f"Is '{word}' in set? {result}")
    
    # Calculate space savings
    traditional_set_size = 100000 * 32  # Assuming 32 bits per string hash
    bloom_size = size
    print(f"\nSpace comparison:")
    print(f"Traditional set: {traditional_set_size} bits")
    print(f"Bloom filter: {bloom_size} bits")
    print(f"Space savings: {(1 - bloom_size/traditional_set_size) * 100:.1f}%")
    print("")


if __name__ == "__main__":
    demonstrate_bloom_filter()

    
