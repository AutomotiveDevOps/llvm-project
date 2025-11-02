; ModuleID = 'cost-analysis-test.c'
source_filename = "cost-analysis-test.c"
target datalayout = "E-m:e-p:32:32-Fn32-i64:64-n32"
target triple = "powerpc"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @vector_dot_product(ptr noundef %0, ptr noundef %1, i32 noundef %2) #0 {
  %4 = alloca ptr, align 4
  %5 = alloca ptr, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store ptr %0, ptr %4, align 4
  store ptr %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  store i32 0, ptr %7, align 4
  store i32 0, ptr %8, align 4
  br label %9

9:                                                ; preds = %25, %3
  %10 = load i32, ptr %8, align 4
  %11 = load i32, ptr %6, align 4
  %12 = icmp slt i32 %10, %11
  br i1 %12, label %13, label %28

13:                                               ; preds = %9
  %14 = load ptr, ptr %4, align 4
  %15 = load i32, ptr %8, align 4
  %16 = getelementptr inbounds i32, ptr %14, i32 %15
  %17 = load i32, ptr %16, align 4
  %18 = load ptr, ptr %5, align 4
  %19 = load i32, ptr %8, align 4
  %20 = getelementptr inbounds i32, ptr %18, i32 %19
  %21 = load i32, ptr %20, align 4
  %22 = mul nsw i32 %17, %21
  %23 = load i32, ptr %7, align 4
  %24 = add nsw i32 %23, %22
  store i32 %24, ptr %7, align 4
  br label %25

25:                                               ; preds = %13
  %26 = load i32, ptr %8, align 4
  %27 = add nsw i32 %26, 1
  store i32 %27, ptr %8, align 4
  br label %9, !llvm.loop !4

28:                                               ; preds = %9
  %29 = load i32, ptr %7, align 4
  ret i32 %29
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @matrix_multiply(ptr noundef %0, ptr noundef %1, ptr noundef %2, i32 noundef %3) #0 {
  %5 = alloca ptr, align 4
  %6 = alloca ptr, align 4
  %7 = alloca ptr, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  store ptr %0, ptr %5, align 4
  store ptr %1, ptr %6, align 4
  store ptr %2, ptr %7, align 4
  store i32 %3, ptr %8, align 4
  store i32 0, ptr %9, align 4
  br label %13

13:                                               ; preds = %63, %4
  %14 = load i32, ptr %9, align 4
  %15 = load i32, ptr %8, align 4
  %16 = icmp slt i32 %14, %15
  br i1 %16, label %17, label %66

17:                                               ; preds = %13
  store i32 0, ptr %10, align 4
  br label %18

18:                                               ; preds = %59, %17
  %19 = load i32, ptr %10, align 4
  %20 = load i32, ptr %8, align 4
  %21 = icmp slt i32 %19, %20
  br i1 %21, label %22, label %62

22:                                               ; preds = %18
  store i32 0, ptr %11, align 4
  store i32 0, ptr %12, align 4
  br label %23

23:                                               ; preds = %47, %22
  %24 = load i32, ptr %12, align 4
  %25 = load i32, ptr %8, align 4
  %26 = icmp slt i32 %24, %25
  br i1 %26, label %27, label %50

27:                                               ; preds = %23
  %28 = load ptr, ptr %5, align 4
  %29 = load i32, ptr %9, align 4
  %30 = load i32, ptr %8, align 4
  %31 = mul nsw i32 %29, %30
  %32 = load i32, ptr %12, align 4
  %33 = add nsw i32 %31, %32
  %34 = getelementptr inbounds i32, ptr %28, i32 %33
  %35 = load i32, ptr %34, align 4
  %36 = load ptr, ptr %6, align 4
  %37 = load i32, ptr %12, align 4
  %38 = load i32, ptr %8, align 4
  %39 = mul nsw i32 %37, %38
  %40 = load i32, ptr %10, align 4
  %41 = add nsw i32 %39, %40
  %42 = getelementptr inbounds i32, ptr %36, i32 %41
  %43 = load i32, ptr %42, align 4
  %44 = mul nsw i32 %35, %43
  %45 = load i32, ptr %11, align 4
  %46 = add nsw i32 %45, %44
  store i32 %46, ptr %11, align 4
  br label %47

47:                                               ; preds = %27
  %48 = load i32, ptr %12, align 4
  %49 = add nsw i32 %48, 1
  store i32 %49, ptr %12, align 4
  br label %23, !llvm.loop !6

50:                                               ; preds = %23
  %51 = load i32, ptr %11, align 4
  %52 = load ptr, ptr %7, align 4
  %53 = load i32, ptr %9, align 4
  %54 = load i32, ptr %8, align 4
  %55 = mul nsw i32 %53, %54
  %56 = load i32, ptr %10, align 4
  %57 = add nsw i32 %55, %56
  %58 = getelementptr inbounds i32, ptr %52, i32 %57
  store i32 %51, ptr %58, align 4
  br label %59

59:                                               ; preds = %50
  %60 = load i32, ptr %10, align 4
  %61 = add nsw i32 %60, 1
  store i32 %61, ptr %10, align 4
  br label %18, !llvm.loop !7

62:                                               ; preds = %18
  br label %63

63:                                               ; preds = %62
  %64 = load i32, ptr %9, align 4
  %65 = add nsw i32 %64, 1
  store i32 %65, ptr %9, align 4
  br label %13, !llvm.loop !8

66:                                               ; preds = %13
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @arithmetic_mix(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  %10 = alloca i32, align 4
  %11 = alloca i32, align 4
  %12 = alloca i32, align 4
  %13 = alloca i32, align 4
  %14 = alloca i32, align 4
  %15 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  %16 = load i32, ptr %4, align 4
  %17 = load i32, ptr %5, align 4
  %18 = add nsw i32 %16, %17
  store i32 %18, ptr %7, align 4
  %19 = load i32, ptr %7, align 4
  %20 = load i32, ptr %6, align 4
  %21 = sub nsw i32 %19, %20
  store i32 %21, ptr %8, align 4
  %22 = load i32, ptr %8, align 4
  %23 = mul nsw i32 %22, 3
  store i32 %23, ptr %9, align 4
  %24 = load i32, ptr %9, align 4
  %25 = sdiv i32 %24, 2
  store i32 %25, ptr %10, align 4
  %26 = load i32, ptr %10, align 4
  %27 = and i32 %26, 255
  store i32 %27, ptr %11, align 4
  %28 = load i32, ptr %11, align 4
  %29 = or i32 %28, 256
  store i32 %29, ptr %12, align 4
  %30 = load i32, ptr %12, align 4
  %31 = xor i32 %30, 85
  store i32 %31, ptr %13, align 4
  %32 = load i32, ptr %13, align 4
  %33 = shl i32 %32, 2
  store i32 %33, ptr %14, align 4
  %34 = load i32, ptr %14, align 4
  %35 = ashr i32 %34, 1
  store i32 %35, ptr %15, align 4
  %36 = load i32, ptr %15, align 4
  ret i32 %36
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @memory_operations(ptr noundef %0, ptr noundef %1, i32 noundef %2) #0 {
  %4 = alloca ptr, align 4
  %5 = alloca ptr, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  store ptr %0, ptr %4, align 4
  store ptr %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  store i32 0, ptr %7, align 4
  br label %9

9:                                                ; preds = %25, %3
  %10 = load i32, ptr %7, align 4
  %11 = load i32, ptr %6, align 4
  %12 = icmp slt i32 %10, %11
  br i1 %12, label %13, label %28

13:                                               ; preds = %9
  %14 = load ptr, ptr %4, align 4
  %15 = load i32, ptr %7, align 4
  %16 = getelementptr inbounds i32, ptr %14, i32 %15
  %17 = load i32, ptr %16, align 4
  store i32 %17, ptr %8, align 4
  %18 = load i32, ptr %8, align 4
  %19 = mul nsw i32 %18, 2
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %8, align 4
  %21 = load i32, ptr %8, align 4
  %22 = load ptr, ptr %5, align 4
  %23 = load i32, ptr %7, align 4
  %24 = getelementptr inbounds i32, ptr %22, i32 %23
  store i32 %21, ptr %24, align 4
  br label %25

25:                                               ; preds = %13
  %26 = load i32, ptr %7, align 4
  %27 = add nsw i32 %26, 1
  store i32 %27, ptr %7, align 4
  br label %9, !llvm.loop !9

28:                                               ; preds = %9
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @conditional_operations(i32 noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  store i32 %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  store i32 0, ptr %7, align 4
  %10 = load i32, ptr %4, align 4
  %11 = load i32, ptr %5, align 4
  %12 = icmp sgt i32 %10, %11
  br i1 %12, label %13, label %17

13:                                               ; preds = %3
  %14 = load i32, ptr %4, align 4
  %15 = load i32, ptr %6, align 4
  %16 = add nsw i32 %14, %15
  store i32 %16, ptr %7, align 4
  br label %21

17:                                               ; preds = %3
  %18 = load i32, ptr %5, align 4
  %19 = load i32, ptr %6, align 4
  %20 = sub nsw i32 %18, %19
  store i32 %20, ptr %7, align 4
  br label %21

21:                                               ; preds = %17, %13
  %22 = load i32, ptr %4, align 4
  %23 = icmp sgt i32 %22, 0
  br i1 %23, label %24, label %26

24:                                               ; preds = %21
  %25 = load i32, ptr %4, align 4
  br label %29

26:                                               ; preds = %21
  %27 = load i32, ptr %4, align 4
  %28 = sub nsw i32 0, %27
  br label %29

29:                                               ; preds = %26, %24
  %30 = phi i32 [ %25, %24 ], [ %28, %26 ]
  store i32 %30, ptr %8, align 4
  %31 = load i32, ptr %5, align 4
  %32 = icmp slt i32 %31, 0
  br i1 %32, label %33, label %36

33:                                               ; preds = %29
  %34 = load i32, ptr %5, align 4
  %35 = mul nsw i32 %34, 2
  br label %39

36:                                               ; preds = %29
  %37 = load i32, ptr %5, align 4
  %38 = sdiv i32 %37, 2
  br label %39

39:                                               ; preds = %36, %33
  %40 = phi i32 [ %35, %33 ], [ %38, %36 ]
  store i32 %40, ptr %9, align 4
  %41 = load i32, ptr %7, align 4
  %42 = load i32, ptr %8, align 4
  %43 = add nsw i32 %41, %42
  %44 = load i32, ptr %9, align 4
  %45 = add nsw i32 %43, %44
  ret i32 %45
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @loop_optimization_test(ptr noundef %0, i32 noundef %1) #0 {
  %3 = alloca ptr, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  %8 = alloca i32, align 4
  %9 = alloca i32, align 4
  store ptr %0, ptr %3, align 4
  store i32 %1, ptr %4, align 4
  store i32 0, ptr %5, align 4
  store i32 1, ptr %6, align 4
  %10 = load ptr, ptr %3, align 4
  %11 = getelementptr inbounds i32, ptr %10, i32 0
  %12 = load i32, ptr %11, align 4
  store i32 %12, ptr %7, align 4
  %13 = load ptr, ptr %3, align 4
  %14 = getelementptr inbounds i32, ptr %13, i32 0
  %15 = load i32, ptr %14, align 4
  store i32 %15, ptr %8, align 4
  store i32 1, ptr %9, align 4
  br label %16

16:                                               ; preds = %57, %2
  %17 = load i32, ptr %9, align 4
  %18 = load i32, ptr %4, align 4
  %19 = icmp slt i32 %17, %18
  br i1 %19, label %20, label %60

20:                                               ; preds = %16
  %21 = load ptr, ptr %3, align 4
  %22 = load i32, ptr %9, align 4
  %23 = getelementptr inbounds i32, ptr %21, i32 %22
  %24 = load i32, ptr %23, align 4
  %25 = load i32, ptr %5, align 4
  %26 = add nsw i32 %25, %24
  store i32 %26, ptr %5, align 4
  %27 = load ptr, ptr %3, align 4
  %28 = load i32, ptr %9, align 4
  %29 = getelementptr inbounds i32, ptr %27, i32 %28
  %30 = load i32, ptr %29, align 4
  %31 = load i32, ptr %6, align 4
  %32 = mul nsw i32 %31, %30
  store i32 %32, ptr %6, align 4
  %33 = load ptr, ptr %3, align 4
  %34 = load i32, ptr %9, align 4
  %35 = getelementptr inbounds i32, ptr %33, i32 %34
  %36 = load i32, ptr %35, align 4
  %37 = load i32, ptr %7, align 4
  %38 = icmp sgt i32 %36, %37
  br i1 %38, label %39, label %44

39:                                               ; preds = %20
  %40 = load ptr, ptr %3, align 4
  %41 = load i32, ptr %9, align 4
  %42 = getelementptr inbounds i32, ptr %40, i32 %41
  %43 = load i32, ptr %42, align 4
  store i32 %43, ptr %7, align 4
  br label %44

44:                                               ; preds = %39, %20
  %45 = load ptr, ptr %3, align 4
  %46 = load i32, ptr %9, align 4
  %47 = getelementptr inbounds i32, ptr %45, i32 %46
  %48 = load i32, ptr %47, align 4
  %49 = load i32, ptr %8, align 4
  %50 = icmp slt i32 %48, %49
  br i1 %50, label %51, label %56

51:                                               ; preds = %44
  %52 = load ptr, ptr %3, align 4
  %53 = load i32, ptr %9, align 4
  %54 = getelementptr inbounds i32, ptr %52, i32 %53
  %55 = load i32, ptr %54, align 4
  store i32 %55, ptr %8, align 4
  br label %56

56:                                               ; preds = %51, %44
  br label %57

57:                                               ; preds = %56
  %58 = load i32, ptr %9, align 4
  %59 = add nsw i32 %58, 1
  store i32 %59, ptr %9, align 4
  br label %16, !llvm.loop !10

60:                                               ; preds = %16
  %61 = load i32, ptr %5, align 4
  %62 = load i32, ptr %6, align 4
  %63 = add nsw i32 %61, %62
  %64 = load i32, ptr %7, align 4
  %65 = load i32, ptr %8, align 4
  %66 = sub nsw i32 %64, %65
  %67 = add nsw i32 %66, 1
  %68 = sdiv i32 %63, %67
  ret i32 %68
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @recursive_sum(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  store i32 %0, ptr %3, align 4
  %4 = load i32, ptr %3, align 4
  %5 = icmp sle i32 %4, 0
  br i1 %5, label %6, label %7

6:                                                ; preds = %1
  store i32 0, ptr %2, align 4
  br label %13

7:                                                ; preds = %1
  %8 = load i32, ptr %3, align 4
  %9 = load i32, ptr %3, align 4
  %10 = sub nsw i32 %9, 1
  %11 = call i32 @recursive_sum(i32 noundef %10)
  %12 = add nsw i32 %8, %11
  store i32 %12, ptr %2, align 4
  br label %13

13:                                               ; preds = %7, %6
  %14 = load i32, ptr %2, align 4
  ret i32 %14
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @strided_access(ptr noundef %0, i32 noundef %1, i32 noundef %2) #0 {
  %4 = alloca ptr, align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  %7 = alloca i32, align 4
  store ptr %0, ptr %4, align 4
  store i32 %1, ptr %5, align 4
  store i32 %2, ptr %6, align 4
  store i32 0, ptr %7, align 4
  br label %8

8:                                                ; preds = %24, %3
  %9 = load i32, ptr %7, align 4
  %10 = load i32, ptr %6, align 4
  %11 = load i32, ptr %5, align 4
  %12 = mul nsw i32 %10, %11
  %13 = icmp slt i32 %9, %12
  br i1 %13, label %14, label %28

14:                                               ; preds = %8
  %15 = load ptr, ptr %4, align 4
  %16 = load i32, ptr %7, align 4
  %17 = getelementptr inbounds i32, ptr %15, i32 %16
  %18 = load i32, ptr %17, align 4
  %19 = mul nsw i32 %18, 2
  %20 = add nsw i32 %19, 1
  %21 = load ptr, ptr %4, align 4
  %22 = load i32, ptr %7, align 4
  %23 = getelementptr inbounds i32, ptr %21, i32 %22
  store i32 %20, ptr %23, align 4
  br label %24

24:                                               ; preds = %14
  %25 = load i32, ptr %5, align 4
  %26 = load i32, ptr %7, align 4
  %27 = add nsw i32 %26, %25
  store i32 %27, ptr %7, align 4
  br label %8, !llvm.loop !11

28:                                               ; preds = %8
  ret void
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @bit_manipulation(i32 noundef %0) #0 {
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, ptr %2, align 4
  store i32 0, ptr %3, align 4
  %6 = load i32, ptr %2, align 4
  store i32 %6, ptr %4, align 4
  br label %7

7:                                                ; preds = %10, %1
  %8 = load i32, ptr %4, align 4
  %9 = icmp ne i32 %8, 0
  br i1 %9, label %10, label %17

10:                                               ; preds = %7
  %11 = load i32, ptr %4, align 4
  %12 = and i32 %11, 1
  %13 = load i32, ptr %3, align 4
  %14 = add nsw i32 %13, %12
  store i32 %14, ptr %3, align 4
  %15 = load i32, ptr %4, align 4
  %16 = ashr i32 %15, 1
  store i32 %16, ptr %4, align 4
  br label %7, !llvm.loop !12

17:                                               ; preds = %7
  store i32 0, ptr %5, align 4
  %18 = load i32, ptr %2, align 4
  store i32 %18, ptr %4, align 4
  br label %19

19:                                               ; preds = %22, %17
  %20 = load i32, ptr %4, align 4
  %21 = icmp sgt i32 %20, 1
  br i1 %21, label %22, label %27

22:                                               ; preds = %19
  %23 = load i32, ptr %5, align 4
  %24 = add nsw i32 %23, 1
  store i32 %24, ptr %5, align 4
  %25 = load i32, ptr %4, align 4
  %26 = ashr i32 %25, 1
  store i32 %26, ptr %4, align 4
  br label %19, !llvm.loop !13

27:                                               ; preds = %19
  %28 = load i32, ptr %3, align 4
  %29 = load i32, ptr %5, align 4
  %30 = mul nsw i32 %28, %29
  ret i32 %30
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [256 x i32], align 4
  %3 = alloca [256 x i32], align 4
  %4 = alloca [65536 x i32], align 4
  %5 = alloca i32, align 4
  %6 = alloca i32, align 4
  store i32 0, ptr %1, align 4
  store i32 0, ptr %5, align 4
  store i32 0, ptr %6, align 4
  br label %7

7:                                                ; preds = %18, %0
  %8 = load i32, ptr %6, align 4
  %9 = icmp slt i32 %8, 256
  br i1 %9, label %10, label %21

10:                                               ; preds = %7
  %11 = load i32, ptr %6, align 4
  %12 = load i32, ptr %6, align 4
  %13 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 %12
  store i32 %11, ptr %13, align 4
  %14 = load i32, ptr %6, align 4
  %15 = sub nsw i32 256, %14
  %16 = load i32, ptr %6, align 4
  %17 = getelementptr inbounds [256 x i32], ptr %3, i32 0, i32 %16
  store i32 %15, ptr %17, align 4
  br label %18

18:                                               ; preds = %10
  %19 = load i32, ptr %6, align 4
  %20 = add nsw i32 %19, 1
  store i32 %20, ptr %6, align 4
  br label %7, !llvm.loop !14

21:                                               ; preds = %7
  %22 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 0
  %23 = getelementptr inbounds [256 x i32], ptr %3, i32 0, i32 0
  %24 = call i32 @vector_dot_product(ptr noundef %22, ptr noundef %23, i32 noundef 256)
  %25 = load i32, ptr %5, align 4
  %26 = add nsw i32 %25, %24
  store i32 %26, ptr %5, align 4
  %27 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 0
  %28 = getelementptr inbounds [256 x i32], ptr %3, i32 0, i32 0
  %29 = getelementptr inbounds [65536 x i32], ptr %4, i32 0, i32 0
  call void @matrix_multiply(ptr noundef %27, ptr noundef %28, ptr noundef %29, i32 noundef 16)
  %30 = call i32 @arithmetic_mix(i32 noundef 100, i32 noundef 200, i32 noundef 50)
  %31 = load i32, ptr %5, align 4
  %32 = add nsw i32 %31, %30
  store i32 %32, ptr %5, align 4
  %33 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 0
  %34 = getelementptr inbounds [256 x i32], ptr %3, i32 0, i32 0
  call void @memory_operations(ptr noundef %33, ptr noundef %34, i32 noundef 256)
  %35 = call i32 @conditional_operations(i32 noundef 10, i32 noundef 20, i32 noundef 5)
  %36 = load i32, ptr %5, align 4
  %37 = add nsw i32 %36, %35
  store i32 %37, ptr %5, align 4
  %38 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 0
  %39 = call i32 @loop_optimization_test(ptr noundef %38, i32 noundef 256)
  %40 = load i32, ptr %5, align 4
  %41 = add nsw i32 %40, %39
  store i32 %41, ptr %5, align 4
  %42 = call i32 @recursive_sum(i32 noundef 100)
  %43 = load i32, ptr %5, align 4
  %44 = add nsw i32 %43, %42
  store i32 %44, ptr %5, align 4
  %45 = getelementptr inbounds [256 x i32], ptr %2, i32 0, i32 0
  call void @strided_access(ptr noundef %45, i32 noundef 4, i32 noundef 64)
  %46 = call i32 @bit_manipulation(i32 noundef 11259375)
  %47 = load i32, ptr %5, align 4
  %48 = add nsw i32 %47, %46
  store i32 %48, ptr %5, align 4
  %49 = load i32, ptr %5, align 4
  ret i32 %49
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="ppc" "target-features"="-aix-small-local-exec-tls,-altivec,-bpermd,-crbits,-crypto,-direct-move,-extdiv,-htm,-isa-v206-instructions,-isa-v207-instructions,-isa-v30-instructions,-power8-vector,-power9-vector,-privileged,-quadword-atomics,-rop-protect,-spe,-vsx" }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"uwtable", i32 2}
!2 = !{i32 7, !"frame-pointer", i32 2}
!3 = !{!"Ubuntu clang version 18.1.3 (1ubuntu1)"}
!4 = distinct !{!4, !5}
!5 = !{!"llvm.loop.mustprogress"}
!6 = distinct !{!6, !5}
!7 = distinct !{!7, !5}
!8 = distinct !{!8, !5}
!9 = distinct !{!9, !5}
!10 = distinct !{!10, !5}
!11 = distinct !{!11, !5}
!12 = distinct !{!12, !5}
!13 = distinct !{!13, !5}
!14 = distinct !{!14, !5}
