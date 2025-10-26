# Instructions
- fetch, decode, execute, memory, write-back
  - nhiều lệnh có thể được xử lý đồng thời – mỗi lệnh ở một giai đoạn khác nhau trong cùng một lúc

- How ?
  
# Hazard
- Data hazard
  - Khi một lệnh cần dữ liệu mà lệnh trước đó chưa kịp tính xong, pipeline phải dừng hoặc xử lý sai.
    - Giải pháp như data forwarding (bypass) và out-of-order execution
- Control hazards
  - Xuất hiện khi gặp lệnh rẽ nhánh (branch), vì CPU chưa biết hướng nào để nạp lệnh tiếp theo.
    - branch prediction động – từ dự đoán tĩnh (thập niên 70) đến bộ dự đoán nhiều tầng và branch target buffer
- Structural hazards
  - Xảy ra khi nhiều lệnh cần cùng một tài nguyên phần cứng (ví dụ ALU hoặc bộ nhớ).
    - thiết kế đa cổng bộ nhớ, nhân xử lý song song, và cơ chế superscalar
  
=> giải pháp về phần cứng, logic điều khiển, và thuật toán tối ưu hóa trình biên dịch