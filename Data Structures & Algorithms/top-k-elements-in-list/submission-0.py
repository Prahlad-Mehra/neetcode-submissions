class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_mapping = {}
        min_heap = []
        for num in nums:
            freq_mapping[num] = freq_mapping.get(num, 0) + 1
        
        for num, freq in freq_mapping.items():
            heapq.heappush(min_heap, (freq, num))
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        return [num for freq, num in min_heap]